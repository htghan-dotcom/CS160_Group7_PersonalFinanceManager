#pragma once
#include "Transaction.h"
#include "Utils.h"

struct RecurringTransaction {
    bool isIncome = true;
    int walletId = 0;
    int sourceOrCategoryId = 0;
    long long amount = 0;
    std::string description;
    std::string startDate;
    std::string endDate;
    int lastCreatedCycle = 0;
};

bool recurringTransactionDue(
    const RecurringTransaction& recurring,
    const std::string& currentDate, std::string& transactionDate
);

int processRecurringTransactions(
    RecurringTransaction* list, int count, const std::string& currentDate,
    IncomeTransaction*& incomeList, int& incomeCount, int& incomeCapacity,
    ExpenseTransaction*& expenseList, int& expenseCount, int& expenseCapacity,
    Wallet* wallets, int walletCount
);
