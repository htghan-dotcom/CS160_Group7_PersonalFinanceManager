#include "ui/Menu.h"
#include "ui/DashboardView.h"
#include "Statistics.h"
#include <ctime>
#include <limits>

namespace {
    long long readNumber(const std::string& prompt, long long minimum, long long maximum) {
        long long value;
        while(true){
            std::cout << prompt;
            if(std::cin >> value){
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if(value >= minimum && value <= maximum){
                    return value;
                }
            }
            else{
                if(std::cin.eof()){
                    return minimum;
                }
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            std::cout << "Invalid number. Please try again.\n";
        }
    }

    std::string readText(const std::string& prompt, bool allowEmpty = false) {
        std::string text;
        do {
            std::cout << prompt;
            if(!std::getline(std::cin, text)){
                return "";
            }
        } while(!allowEmpty && text.find_first_not_of(" \t\r") == std::string::npos);
        return text;
    }

    std::string readDate(const std::string& prompt, bool allowEmpty = false) {
        while(true){
            std::string text = readText(prompt, allowEmpty);
            if(std::cin.eof() || (allowEmpty && text.empty())){
                return text;
            }
            date d{};
            if(parsingDate(text, d) && dateValid(d) && d.year >= 1){
                return text;
            }
            std::cout << "Invalid date. Use DD/MM/YYYY.\n";
        }
    }

    std::string currentDate() {
        std::time_t now = std::time(nullptr);
        std::tm* today = std::localtime(&now);
        char text[11]{};
        if(today != nullptr){
            std::strftime(text, sizeof(text), "%d/%m/%Y", today);
        }
        return text;
    }

    int selectWallet(Wallet* wallets, int count) {
        if(count == 0){
            std::cout << "Please add a wallet first.\n";
            return -1;
        }
        DashboardView::renderDashboard(wallets, count);
        int id = static_cast<int>(readNumber("Wallet ID: ", 1, 2147483647));
        if(findWalletIndexById(wallets, count, id) == -1){
            std::cout << "Wallet not found.\n";
            return -1;
        }
        return id;
    }

    int selectSource(MasterDataManager& data, bool isIncome) {
        if(isIncome){
            data.displayIncomeSources();
        }
        else{
            data.displayExpenseCategories();
        }
        if((isIncome ? data.incomeCount : data.expenseCount) == 0){
            return -1;
        }
        int id = static_cast<int>(readNumber(isIncome ? "Source ID: " : "Category ID: ", 1, 2147483647));
        bool exists = isIncome ? data.isIncomeSourceIdExists(id) : data.isExpenseCategoryExists(id);
        if(!exists){
            std::cout << "ID not found.\n";
            return -1;
        }
        return id;
    }

    std::string getWalletName(const Wallet* wallets, int count, int id) {
        int index = findWalletIndexById(wallets, count, id);
        return index == -1 ? "Unknown" : wallets[index].name;
    }

    std::string getSourceName(const MasterDataManager& data, int id, bool isIncome) {
        if(isIncome){
            for(int i = 0; i < data.incomeCount; i++){
                if(data.incomeSources[i].sourceID == id){
                    return data.incomeSources[i].sourceName;
                }
            }
        }
        else{
            for(int i = 0; i < data.expenseCount; i++){
                if(data.expenseCategories[i].categoryID == id){
                    return data.expenseCategories[i].categoryName;
                }
            }
        }
        return "Unknown";
    }

    void walletMenu(Wallet*& wallets, int& count) {
        DashboardView::renderDashboard(wallets, count);
        int choice = static_cast<int>(readNumber("1. Add wallet\n2. Rename wallet\n3. Delete wallet\n0. Back\nChoice: ", 0, 3));
        if(choice == 0){
            return;
        }
        int id = static_cast<int>(readNumber("Wallet ID: ", 1, 2147483647));
        if(choice == 1){
            if(findWalletIndexById(wallets, count, id) != -1){
                std::cout << "Wallet ID already exists.\n";
                return;
            }
            std::string name = readText("Wallet name: ");
            long long balance = readNumber("Initial balance: ", 0, std::numeric_limits<long long>::max());
            if(std::cin.eof()){
                return;
            }
            addWallet(wallets, count, Wallet{id, name, static_cast<long double>(balance)});
            std::cout << "Wallet added.\n";
        }
        else if(choice == 2){
            std::string name = readText("New name: ");
            std::cout << (editWallet(wallets, count, id, name) ? "Wallet renamed.\n" : "Wallet not found.\n");
        }
        else{
            std::cout << (deleteWallet(wallets, count, id) ? "Wallet deleted.\n" : "Wallet not found.\n");
        }
    }

    void incomeSourcesMenu(MasterDataManager& data) {
        data.displayIncomeSources();
        int choice = static_cast<int>(readNumber("1. Add source\n2. Rename source\n3. Delete source\n0. Back\nChoice: ", 0, 3));
        if(std::cin.eof()){
            return;
        }
        switch(choice){
            case 1: data.addIncomeSource(); break;
            case 2: data.updateIncomeSource(); break;
            case 3: data.deleteIncomeSource(); break;
        }
    }

    void expenseCategoriesMenu(MasterDataManager& data) {
        data.displayExpenseCategories();
        int choice = static_cast<int>(readNumber("1. Add category\n2. Rename category\n3. Delete category\n0. Back\nChoice: ", 0, 3));
        if(std::cin.eof()){
            return;
        }
        switch(choice){
            case 1: data.addExpenseCategory(); break;
            case 2: data.updateExpenseCategory(); break;
            case 3: data.deleteExpenseCategory(); break;
        }
    }

    void incomeMenu(MasterDataManager& data, Wallet* wallets, int walletCount,
                    IncomeTransaction*& list, int& count, int& capacity) {
        int walletId = selectWallet(wallets, walletCount);
        if(walletId == -1){
            return;
        }
        int sourceId = selectSource(data, true);
        if(sourceId == -1){
            return;
        }
        long long amount = readNumber("Amount: ", 1, std::numeric_limits<long long>::max());
        std::string dateText = readDate("Date (DD/MM/YYYY): ");
        std::string description = readText("Description (optional): ", true);
        if(std::cin.eof()){
            return;
        }
        bool saved = recordIncome(list, count, capacity, dateText, sourceId,
                                  amount, walletId, description, wallets, walletCount);
        std::cout << (saved ? "Income recorded; wallet balance updated.\n" : "Cannot record income.\n");
    }

    void expenseMenu(MasterDataManager& data, Wallet* wallets, int walletCount,
                     ExpenseTransaction*& list, int& count, int& capacity) {
        int walletId = selectWallet(wallets, walletCount);
        if(walletId == -1){
            return;
        }
        int categoryId = selectSource(data, false);
        if(categoryId == -1){
            return;
        }
        long long amount = readNumber("Amount: ", 1, std::numeric_limits<long long>::max());
        std::string dateText = readDate("Date (DD/MM/YYYY): ");
        std::string description = readText("Description (optional): ", true);
        if(std::cin.eof()){
            return;
        }
        bool saved = recordExpense(list, count, capacity, dateText, categoryId,
                                   amount, walletId, description, wallets, walletCount);
        std::cout << (saved ? "Expense recorded; wallet balance updated.\n" : "Cannot record expense. Check wallet balance.\n");
    }

    void historyMenu(const MasterDataManager& data, const Wallet* wallets, int walletCount,
                     const IncomeTransaction* incomes, int incomeCount,
                     const ExpenseTransaction* expenses, int expenseCount) {
        std::cout << "\nINCOME HISTORY\nID | Date | Source | Wallet | Amount | Description\n";
        if(incomeCount == 0){
            std::cout << "No income transactions.\n";
        }
        for(int i = 0; i < incomeCount; i++){
            const IncomeTransaction& t = incomes[i];
            std::cout << t.id << " | " << t.date << " | " << getSourceName(data, t.sourceId, true)
                      << " | " << getWalletName(wallets, walletCount, t.walletId)
                      << " | +" << t.amount << " | " << t.description << '\n';
        }
        std::cout << "\nEXPENSE HISTORY\nID | Date | Category | Wallet | Amount | Description\n";
        if(expenseCount == 0){
            std::cout << "No expense transactions.\n";
        }
        for(int i = 0; i < expenseCount; i++){
            const ExpenseTransaction& t = expenses[i];
            std::cout << t.id << " | " << t.date << " | " << getSourceName(data, t.categoryId, false)
                      << " | " << getWalletName(wallets, walletCount, t.walletId)
                      << " | -" << t.amount << " | " << t.description << '\n';
        }
    }

    void statisticsMenu(MasterDataManager& data, Wallet* wallets, int walletCount,
                        const IncomeTransaction* incomes, int incomeCount,
                        const ExpenseTransaction* expenses, int expenseCount) {
        int choice = static_cast<int>(readNumber(
            "1. Date range overview\n2. Wallet/date range overview\n3. Annual overview\n"
            "4. Annual income breakdown\n5. Annual expense breakdown\n0. Back\nChoice: ", 0, 5));
        if(choice == 0){
            return;
        }
        if(choice <= 2){
            int walletId = -1;
            if(choice == 2){
                walletId = selectWallet(wallets, walletCount);
                if(walletId == -1){
                    return;
                }
            }
            std::string start = readDate("Start date (DD/MM/YYYY): ");
            std::string end = readDate("End date (DD/MM/YYYY): ");
            if(std::cin.eof()){
                return;
            }
            if(choice == 1){
                timeOverview(incomes, incomeCount, expenses, expenseCount, start, end);
            }
            else{
                Wallet* wallet = getWalletById(wallets, walletCount, walletId);
                walletOverview(incomes, incomeCount, expenses, expenseCount, *wallet, start, end);
            }
        }
        else{
            int count = static_cast<int>(readNumber("Number of years: ", 1, 9999));
            for(int i = 0; i < count; i++){
                int year = static_cast<int>(readNumber("Year: ", 1, 9999));
                if(std::cin.eof()){
                    return;
                }
                if(choice == 3){
                    annualOverview(incomes, incomeCount, expenses, expenseCount, year);
                }
                else if(choice == 4){
                    annualIncomeBreakdown(incomes, incomeCount, data.incomeSources, data.incomeCount, year);
                }
                else{
                    annualExpenseBreakdown(expenses, expenseCount, data.expenseCategories, data.expenseCount, year);
                }
            }
        }
    }

    void recurringMenu(MasterDataManager& data, Wallet* wallets, int walletCount,
                       IncomeTransaction*& incomes, int& incomeCount, int& incomeCapacity,
                       ExpenseTransaction*& expenses, int& expenseCount, int& expenseCapacity,
                       RecurringTransaction*& list, int& count) {
        int choice = static_cast<int>(readNumber("1. Add schedule\n2. View schedules\n3. Check current cycle\n0. Back\nChoice: ", 0, 3));
        if(choice == 1){
            bool isIncome = readNumber("1. Income\n2. Expense\nType: ", 1, 2) == 1;
            int walletId = selectWallet(wallets, walletCount);
            if(walletId == -1){
                return;
            }
            int sourceId = selectSource(data, isIncome);
            if(sourceId == -1){
                return;
            }
            long long amount = readNumber("Amount: ", 1, std::numeric_limits<long long>::max());
            std::string start = readDate("Start date (DD/MM/YYYY): ");
            std::string end = readDate("End date (blank for indefinite): ", true);
            date a{}, b{};
            if(!end.empty() && parsingDate(start, a) && parsingDate(end, b) && cmpDate(a, b) > 0){
                std::cout << "End date must not precede start date.\n";
                return;
            }
            std::string description = readText("Description (optional): ", true);
            if(std::cin.eof()){
                return;
            }
            RecurringTransaction* next = new RecurringTransaction[count + 1];
            for(int i = 0; i < count; i++){
                next[i] = list[i];
            }
            next[count] = {isIncome, walletId, sourceId, amount, description, start, end, 0};
            delete[] list;
            list = next;
            count++;
            std::cout << "Schedule added. Use Check current cycle to process it.\n";
        }
        else if(choice == 2){
            if(count == 0){
                std::cout << "No recurring schedules.\n";
            }
            for(int i = 0; i < count; i++){
                const RecurringTransaction& r = list[i];
                std::cout << i + 1 << " | " << (r.isIncome ? "Income" : "Expense")
                          << " | " << getWalletName(wallets, walletCount, r.walletId)
                          << " | " << getSourceName(data, r.sourceOrCategoryId, r.isIncome)
                          << " | " << r.amount << " | " << r.startDate << " - "
                          << (r.endDate.empty() ? "Indefinite" : r.endDate)
                          << " | Last cycle: " << r.lastCreatedCycle << '\n';
            }
        }
        else if(choice == 3){
            std::string today = currentDate();
            if(today.empty()){
                std::cout << "Cannot read the current date.\n";
                return;
            }
            int added = processRecurringTransactions(list, count, today,
                incomes, incomeCount, incomeCapacity, expenses, expenseCount, expenseCapacity,
                wallets, walletCount);
            std::cout << "Date: " << today << " | Transactions added: " << added
                      << "\nSchedules not due, already processed or unsuccessful were skipped.\n";
        }
    }
}

void MenuSystem::runMainLoop(
    MasterDataManager& masterManager, Wallet*& wallets, int& walletCount,
    IncomeTransaction*& incomeList, int& incomeCount, int& incomeCapacity,
    ExpenseTransaction*& expenseList, int& expenseCount, int& expenseCapacity,
    RecurringTransaction*& recurringList, int& recurringCount
) {
    std::string today = currentDate();
    if(!today.empty()){
        processRecurringTransactions(recurringList, recurringCount, today,
            incomeList, incomeCount, incomeCapacity, expenseList, expenseCount, expenseCapacity,
            wallets, walletCount);
    }
    std::cout << "Session mode: data is kept until you exit.\n";
    while(!std::cin.eof()){
        DashboardView::renderDashboard(wallets, walletCount);
        std::cout << "\n--------------MAIN MENU--------------\n"
                  << "1. Wallets\n2. Income sources\n3. Expense categories\n"
                  << "4. Record income\n5. Record expense\n6. Transaction history\n"
                  << "7. Statistics\n8. Recurring transactions\n0. Exit\n";
        int choice = static_cast<int>(readNumber("Choice: ", 0, 8));
        if(choice == 0 || std::cin.eof()){
            break;
        }
        switch(choice){
            case 1:
                walletMenu(wallets, walletCount);
                break;
            case 2:
                incomeSourcesMenu(masterManager);
                break;
            case 3:
                expenseCategoriesMenu(masterManager);
                break;
            case 4:
                incomeMenu(masterManager, wallets, walletCount, incomeList, incomeCount, incomeCapacity);
                break;
            case 5:
                expenseMenu(masterManager, wallets, walletCount, expenseList, expenseCount, expenseCapacity);
                break;
            case 6:
                historyMenu(masterManager, wallets, walletCount, incomeList, incomeCount, expenseList, expenseCount);
                break;
            case 7:
                statisticsMenu(masterManager, wallets, walletCount, incomeList, incomeCount, expenseList, expenseCount);
                break;
            case 8:
                recurringMenu(masterManager, wallets, walletCount,
                    incomeList, incomeCount, incomeCapacity, expenseList, expenseCount, expenseCapacity,
                    recurringList, recurringCount);
                break;
        }
    }
    std::cout << "Exiting application. Session data will be cleared.\n";
}
