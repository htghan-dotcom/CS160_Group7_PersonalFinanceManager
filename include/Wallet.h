#pragma once

struct Wallet {
    std::string id;
    std::string name;
    long double balance;
};

void addWallet(Wallet*& Wallets, int& walletCount, Wallet newWallet);

void editWallet(Wallet*& Wallets, int walletCount, Wallet )