#include "DashboardView.h"
#include "Wallet.h" 
#include <iostream>
#include <iomanip>

void DashboardView::renderDashboard(const Wallet* wallets, int walletCount) {
    long double totalBalance = getTotalBalance(wallets, walletCount);

    std::cout << "=====================================================================\n";
    std::cout << "                   PERSONAL FINANCE MANAGER - DASHBOARD              \n";
    std::cout << "=====================================================================\n";
    std::cout << " >> AGGREGATE TOTAL BALANCE: " 
              << std::fixed << std::setprecision(0) << totalBalance << " VND\n";
    std::cout << "---------------------------------------------------------------------\n";

    std::cout << "+----------+----------------------------------+---------------------+\n";
    std::cout << "| " << std::left << std::setw(8) << "WALLET ID" 
              << " | " << std::setw(32) << "WALLET NAME" 
              << " | " << std::right << std::setw(19) << "BALANCE (VND)" << " |\n";
    std::cout << "+----------+----------------------------------+---------------------+\n";

    if (walletCount == 0 || wallets == nullptr) {
        std::cout << "| " << std::left << std::setw(65) << "No wallets available. Please add a wallet first." << " |\n";
    } else {
        for (int i = 0; i < walletCount; ++i) {
            std::cout << "| " << std::left << std::setw(8) << wallets[i].id
                      << " | " << std::setw(32) << wallets[i].name
                      << " | " << std::right << std::setw(19) << std::fixed << std::setprecision(0) << wallets[i].balance << " |\n";
        }
    }

    std::cout << "+----------+----------------------------------+---------------------+\n";
}