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
// Income-only overview for one year. Call once per selected year.
void annualOverview(
    const IncomeTransaction* incomeList,
    int incomeCount,
    int year
);
// Income-only overview for a selected wallet and inclusive date range.
void walletIncomeOverview(
    const IncomeTransaction* incomeList,
    int incomeCount,
    const Wallet& wallet,
    const std::string& dateStart,
    const std::string& dateEnd
);