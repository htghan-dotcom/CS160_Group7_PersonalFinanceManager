#pragma once
#include "Transaction.h"
#include "Utils.h"
#include "Wallet.h"
#include "models/IncomeSource.h"
#include "models/ExpenseCategory.h"

long long totalIncomeRange(
    const IncomeTransaction* incomeList,
    int incomeCount,
    const std::string& dateStart,
    const std::string& dateEnd,
    int walletId = -1,
    int sourceId = -1
);

void annualIncomeBreakdown(
    const IncomeTransaction* incomeList,
    int incomeCount,
    const IncomeSource* incomeSources,
    int sourceCount,
    int year
);
long long totalExpenseRange(
    const ExpenseTransaction* expenseList,
    int expenseCount,
    const std::string& dateStart,
    const std::string& dateEnd,
    int walletId = -1,
    int categoryId = -1
);

void annualExpenseBreakdown(
    const ExpenseTransaction* expenseList,
    int expenseCount,
    const ExpenseCategory* expenseCategories,
    int categoryCount,
    int year
);

// Income, expense and their difference within an inclusive date range.
void timeOverview(
    const IncomeTransaction* incomeList,
    int incomeCount,
    const ExpenseTransaction* expenseList,
    int expenseCount,
    const std::string& dateStart,
    const std::string& dateEnd,
    int walletId = -1
);

// Full overview for one year; call once per selected year.
void annualOverview(
    const IncomeTransaction* incomeList,
    int incomeCount,
    const ExpenseTransaction* expenseList,
    int expenseCount,
    int year
);

void walletOverview(
    const IncomeTransaction* incomeList,
    int incomeCount,
    const ExpenseTransaction* expenseList,
    int expenseCount,
    const Wallet& wallet,
    const std::string& dateStart,
    const std::string& dateEnd
);