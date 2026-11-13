#pragma once
#include "Wallet.h"

class DashboardView {
public:
    static void renderDashboard(const Wallet* wallets, int walletCount);
};