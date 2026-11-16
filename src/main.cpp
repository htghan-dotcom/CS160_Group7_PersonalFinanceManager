#include "managers/MasterDataManager.h"
#include "ui/Menu.h"
#include "Wallet.h"
#include "Transaction.h"

int main() {
    MasterDataManager masterManager;

    Wallet* wallets = nullptr;
    int walletCount = 0;

    IncomeTransaction* incomeList = nullptr;
    int incomeCount = 0;
    int incomeCapacity = 0;

    MenuSystem::runMainLoop(masterManager, wallets, walletCount, incomeList, incomeCount, incomeCapacity);

    freeWallets(wallets, walletCount);
    freeIncomeList(incomeList, incomeCount, incomeCapacity);

    return 0;
}