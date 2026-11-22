#include "Statistics.h"

long long totalIncomeRange(
    const IncomeTransaction* incomeList,
    int incomeCount,
    const std::string& dateStart,
    const std::string& dateEnd,
    int walletId,
    int sourceId
) {
    if(incomeList == nullptr && incomeCount != 0){
        std::cout << "Invalid income list.\n";
        return -1;
    }

    date start{}, end{};
    if(!parsingDate(dateStart, start) ||
        !parsingDate(dateEnd, end) || !dateValid(start) || !dateValid(end)){
        std::cout << "Invalid start or end date.\n";
        return -1;
    }
    if(cmpDate(start, end) > 0){
        std::cout << "Invalid date range.\n";
        return -1;
    }

    long long total = 0;
    for (int i = 0; i < incomeCount; i++) {
        const IncomeTransaction& data = incomeList[i];

        bool matchesWallet = walletId == -1 || data.walletId == walletId;
        bool matchesSource = sourceId == -1 || data.sourceId == sourceId;
        if(!matchesWallet || !matchesSource){
            continue;
        }

        date d{};
        if(!parsingDate(data.date, d) || !dateValid(d)){
            std::cout << "Invalid income transaction date.\n";
            return -1;
        }

        if(cmpDate(start, d) <= 0 &&
            cmpDate(d, end) <= 0){
            total += data.amount;
        }
    }
    return total;
}

void annualIncomeBreakdown(
    const IncomeTransaction* incomeList,
    int incomeCount,
    const IncomeSource* incomeSources,
    int sourceCount,
    int year
) {
    if(year < 1 || year > 9999 || sourceCount < 0 || 
        (incomeList == nullptr && incomeCount != 0) || (incomeSources == nullptr && sourceCount != 0)){
        std::cout << "Invalid annual income breakdown input.\n";
        return;
    }

    std::string yearText = std::to_string(year);
    yearText = std::string(4 - yearText.size(), '0') + yearText;
    std::string dateStart = "01/01/" + yearText;
    std::string dateEnd = "31/12/" + yearText;

    std::cout << "Income breakdown for " << year << ":\n";
    for (int i = 0; i < sourceCount; i++) {
        long long total = totalIncomeRange(
            incomeList, incomeCount, dateStart, dateEnd,
            -1, incomeSources[i].sourceID
        );
        if(total == -1){
            return;
        }
        std::cout << incomeSources[i].sourceName << ": " << total << '\n';
    }
}
long long totalExpenseRange(
    const ExpenseTransaction* expenseList,
    int expenseCount,
    const std::string& dateStart,
    const std::string& dateEnd,
    int walletId,
    int categoryId
) {
    if(expenseList == nullptr && expenseCount != 0){
        std::cout << "Invalid expense list.\n";
        return -1;
    }

    date start{}, end{};
    if(!parsingDate(dateStart, start) ||
        !parsingDate(dateEnd, end) || !dateValid(start) || !dateValid(end)){
        std::cout << "Invalid start or end date.\n";
        return -1;
    }
    if(cmpDate(start, end) > 0){
        std::cout << "Invalid date range.\n";
        return -1;
    }

    long long total = 0;
    for (int i = 0; i < expenseCount; i++) {
        const ExpenseTransaction& data = expenseList[i];

        bool matchesWallet = walletId == -1 || data.walletId == walletId;
        bool matchesCategory = categoryId == -1 || data.categoryId == categoryId;
        if(!matchesWallet || !matchesCategory){
            continue;
        }

        date d{};
        if(!parsingDate(data.date, d) || !dateValid(d)){
            std::cout << "Invalid expense transaction date.\n";
            return -1;
        }

        if(cmpDate(start, d) <= 0 &&
            cmpDate(d, end) <= 0){
            total += data.amount;
        }
    }
    return total;
}


void annualExpenseBreakdown(
    const ExpenseTransaction* expenseList,
    int expenseCount,
    const ExpenseCategory* expenseCategories,
    int categoryCount,
    int year
) {
    if(year < 1 || year > 9999 || categoryCount < 0 ||
        (expenseList == nullptr && expenseCount != 0) || (expenseCategories == nullptr && categoryCount != 0)){
        std::cout << "Invalid annual expense breakdown input.\n";
        return;
    }

    std::string yearText = std::to_string(year);
    yearText = std::string(4 - yearText.size(), '0') + yearText;
    std::string dateStart = "01/01/" + yearText;
    std::string dateEnd = "31/12/" + yearText;

    std::cout << "Expense breakdown for " << year << ":\n";
    for (int i = 0; i < categoryCount; i++) {
        long long total = totalExpenseRange(
            expenseList, expenseCount, dateStart, dateEnd,
            -1, expenseCategories[i].categoryID
        );
        if(total == -1){
            return;
        }
        std::cout << expenseCategories[i].categoryName << ": " << total << '\n';
    }
}

void timeOverview(
    const IncomeTransaction* incomeList,
    int incomeCount,
    const ExpenseTransaction* expenseList,
    int expenseCount,
    const std::string& dateStart,
    const std::string& dateEnd,
    int walletId
) {
    long long income = totalIncomeRange(
        incomeList, incomeCount, dateStart, dateEnd, walletId
    );
    if(income == -1){
        return;
    }
    long long expense = totalExpenseRange(
        expenseList, expenseCount, dateStart, dateEnd, walletId
    );
    if(expense == -1){
        return;
    }

    std::cout << "Period: " << dateStart << " - " << dateEnd << '\n';
    std::cout << "Total income: " << income << '\n';
    std::cout << "Total expense: " << expense << '\n';
    std::cout << "Net balance: " << income - expense << '\n';
}

void annualOverview(
    const IncomeTransaction* incomeList,
    int incomeCount,
    const ExpenseTransaction* expenseList,
    int expenseCount,
    int year
) {
    if(year < 1 || year > 9999){
        std::cout << "Invalid year.\n";
        return;
    }
    std::string yearText = std::to_string(year);
    yearText = std::string(4 - yearText.size(), '0') + yearText;
    std::cout << "Annual overview for " << year << ":\n";
    timeOverview(incomeList, incomeCount, expenseList, expenseCount,
                 "01/01/" + yearText, "31/12/" + yearText);
}

void walletOverview(
    const IncomeTransaction* incomeList,
    int incomeCount,
    const ExpenseTransaction* expenseList,
    int expenseCount,
    const Wallet& wallet,
    const std::string& dateStart,
    const std::string& dateEnd
) {
    if(wallet.id <= 0){
        std::cout << "Invalid wallet ID.\n";
        return;
    }
    std::cout << "Wallet: " << wallet.name << " (ID: " << wallet.id << ")\n";
    timeOverview(incomeList, incomeCount, expenseList, expenseCount,
                 dateStart, dateEnd, wallet.id);
}