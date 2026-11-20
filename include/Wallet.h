#pragma once
#include <string>

struct Wallet {
    int id;
    std::string name;
    long double balance;
};

void addWallet(Wallet*& wallets, int& walletCount, const Wallet& newWallet);
void editWallet(Wallet*& wallets, int walletCount, const int& id, const std::string& newName);
bool deleteWallet(Wallet*& wallets, int& walletCount, const int& id);
void freeWallets(Wallet*& wallets, int& walletCount);

// Searching and calculating functions
int findWalletIndexById(const Wallet* wallets, int walletCount, const int& id);
Wallet* getWalletById(Wallet* wallets, int walletCount, const int& id);
bool updateWalletBalance(Wallet* wallets, int walletCount, const int& id, long double amountChange);
long double getTotalBalance(const Wallet* wallets, int walletCount);