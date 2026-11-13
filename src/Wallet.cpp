#include "Wallet.h"
#include <iostream>
#include <fstream>

void addWallet(Wallet*& wallets, int& walletCount, const Wallet& newWallet) {
    if (findWalletIndexById(wallets, walletCount, newWallet.id) != -1) {
        return; 
    }

    Wallet* temp = new Wallet[walletCount + 1];
    for (int i = 0; i < walletCount; ++i) {
        temp[i] = wallets[i];
    }
    temp[walletCount] = newWallet;

    delete[] wallets;
    wallets = temp;
    ++walletCount;
}

bool editWallet(Wallet* wallets, int walletCount, const int& id, const std::string& newName) {
    int idx = findWalletIndexById(wallets, walletCount, id);
    if (idx == -1 || newName.empty()) {
        return false;
    }
    wallets[idx].name = newName;
    return true;
}

bool deleteWallet(Wallet*& wallets, int& walletCount, const int& id) {
    int idx = findWalletIndexById(wallets, walletCount, id);
    if (idx == -1) {
        return false;
    }

    if (walletCount == 1) {
        delete[] wallets;
        wallets = nullptr;
        walletCount = 0;
        return true;
    }

    Wallet* temp = new Wallet[walletCount - 1];
    for (int i = 0, j = 0; i < walletCount; ++i) {
        if (i != idx) {
            temp[j++] = wallets[i];
        }
    }

    delete[] wallets;
    wallets = temp;
    --walletCount;
    return true;
}

void freeWallets(Wallet*& wallets, int& walletCount) {
    delete[] wallets;
    wallets = nullptr;
    walletCount = 0;
}

int findWalletIndexById(const Wallet* wallets, int walletCount, const int& id) {
    for (int i = 0; i < walletCount; ++i) {
        if (wallets[i].id == id) {
            return i;
        }
    }
    return -1;
}

Wallet* getWalletById(Wallet* wallets, int walletCount, const int& id) {
    int idx = findWalletIndexById(wallets, walletCount, id);
    if (idx == -1) {
        return nullptr;
    }
    return &wallets[idx];
}

bool updateWalletBalance(Wallet* wallets, int walletCount, const int& id, long double amountChange) {
    int idx = findWalletIndexById(wallets, walletCount, id);
    if (idx == -1) {
        return false;
    }

    if (wallets[idx].balance + amountChange < 0) {
        return false;
    }
    wallets[idx].balance += amountChange;
    return true;
}

long double getTotalBalance(const Wallet* wallets, int walletCount) {
    long double total = 0.0;
    for (int i = 0; i < walletCount; ++i) {
        total += wallets[i].balance;
    }
    return total;
}
