#include "ui/Menu.h"
#include "ui/DashboardView.h"
#include "Utils.h"
#include <iostream>

void MenuSystem::runMainLoop(MasterDataManager& masterManager, Wallet*& wallets, int& walletcount, IncomeTransaction*& incomeList, int& incomeCount, int& incomeCapacity){
    while(true){
        ConsoleUtils::clearScreen();
        DashboardView::renderDashboard(wallets,walletcount);

        std::cout << "\n--------------MAIN MENU--------------\n";
        std::cout << "1. Manage Wallets\n";
        std::cout << "2. Manage Income Sources\n";
        std::cout << "3. Manage Expense Categories\n";
        std::cout << "4. Record New Income Transaction\n";
        std::cout << "5. View Income Transaction History\n";
        std::cout << "0. Exit Application\n";
        std::cout << "Select an option: ";

        int choice = ConsoleUtils::getValidChoice();
        
        if (choice == 0){
            std::cout << "Exiting Application...\n";
            return;
        }

        std::cout << "\n[Test] Feature " << choice << " is under construction.\n";
        ConsoleUtils::pauseScreen();
    }
}