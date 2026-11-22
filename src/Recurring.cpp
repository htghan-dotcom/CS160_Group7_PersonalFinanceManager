#include "Recurring.h"

bool recurringTransactionDue(
    const RecurringTransaction& recurring,
    const std::string& currentDate, std::string& transactionDate
) {
    date today{}, start{}, end{};
    if(!parsingDate(currentDate, today) || !dateValid(today) || today.year < 1 ||
        !parsingDate(recurring.startDate, start) || !dateValid(start) || start.year < 1){
        return false;
    }
    if(!recurring.endDate.empty() &&
        (!parsingDate(recurring.endDate, end) || !dateValid(end) || cmpDate(start, end) > 0)){
        return false;
    }

    int cycle = today.year * 100 + today.month;
    if(cmpDate(today, start) < 0 || cycle <= recurring.lastCreatedCycle){
        return false;
    }

    date due{start.day, today.month, today.year};
    while (!dateValid(due)) {
        due.day--;
    }
    if(cmpDate(today, due) < 0 ||
        (!recurring.endDate.empty() && cmpDate(due, end) > 0)){
        return false;
    }

    transactionDate = (due.day < 10 ? "0" : "") + std::to_string(due.day) + currentDate.substr(2);
    return true;
}

int processRecurringTransactions(
    RecurringTransaction* list, int count, const std::string& currentDate,
    IncomeTransaction*& incomeList, int& incomeCount, int& incomeCapacity,
    ExpenseTransaction*& expenseList, int& expenseCount, int& expenseCapacity,
    Wallet* wallets, int walletCount
) {
    date today{};
    if((list == nullptr && count != 0) ||
        !parsingDate(currentDate, today) || !dateValid(today) || today.year < 1){
        return -1;
    }

    int added = 0;
    for (int i = 0; i < count; i++) {
        RecurringTransaction& recurring = list[i];
        std::string transactionDate;
        if(!recurringTransactionDue(recurring, currentDate, transactionDate)){
            continue;
        }

        bool created;
        if(recurring.isIncome){
            created = recordIncome(incomeList, incomeCount, incomeCapacity,
                transactionDate, recurring.sourceOrCategoryId, recurring.amount,
                recurring.walletId, recurring.description,
                wallets, walletCount);
        }
        else{
            created = recordExpense(expenseList, expenseCount, expenseCapacity,
                transactionDate, recurring.sourceOrCategoryId, recurring.amount,
                recurring.walletId, recurring.description,
                wallets, walletCount);
        }
        if(created){
            recurring.lastCreatedCycle = today.year * 100 + today.month;
            added++;
        }
    }
    return added;
}
