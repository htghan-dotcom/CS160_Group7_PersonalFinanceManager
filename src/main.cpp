#include "ui/Menu.h"

int main() {
    MasterDataManager masterManager;
    Wallet* wallets = nullptr;
    int walletCount = 0;
    IncomeTransaction* incomeList = nullptr;
    int incomeCount = 0, incomeCapacity = 0;
    ExpenseTransaction* expenseList = nullptr;
    int expenseCount = 0, expenseCapacity = 0;
    RecurringTransaction* recurringList = nullptr;
    int recurringCount = 0;

    MenuSystem::runMainLoop(masterManager, wallets, walletCount,
        incomeList, incomeCount, incomeCapacity,
        expenseList, expenseCount, expenseCapacity,
        recurringList, recurringCount);

    freeWallets(wallets, walletCount);
    freeIncomeList(incomeList, incomeCount, incomeCapacity);
    freeExpenseList(expenseList, expenseCount, expenseCapacity);
    delete[] recurringList;
    return 0;
}
