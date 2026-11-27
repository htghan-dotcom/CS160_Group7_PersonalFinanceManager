#pragma once
#include "../managers/MasterDataManager.h"
#include "../Wallet.h"
#include "../Transaction.h"
#include "../Recurring.h"

class MenuSystem {
    public:
        static void runMainLoop(
            MasterDataManager& masterManager,
            Wallet*& wallets, int& walletCount,
            IncomeTransaction*& incomeList, int& incomeCount, int& incomeCapacity,
            ExpenseTransaction*& expenseList, int& expenseCount, int& expenseCapacity,
            RecurringTransaction*& recurringList, int& recurringCount
        );
};
