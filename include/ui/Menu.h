#pragma once
#include "managers/MasterDataManager.h"
#include "ConsoleUtils.h"
#include "Wallet.h"
#include "Transaction.h"

class MenuSystem {
    public:
        static void runMainLoop(MasterDataManager& masterManager, Wallet*& wallets, int& walletcount, IncomeTransaction*& incomeList, int& incomeCount, int& incomeCapacity);
};