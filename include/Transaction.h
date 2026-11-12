#pragma once

#include <iostream>
#include <string>

struct IncomeTransaction {
    int id;
    std::string date;
    int sourceId;
    long long amount;
    int walletId;
    std::string description;
};

int nextIncomeId(const IncomeTransaction* list, int count);

bool recordIncome(IncomeTransaction*& list, int& count, int& capacity,
                  const std::string& date, int sourceId,
                  long long amount, int walletId,
                  const std::string& description);

std::string incomeToString(const IncomeTransaction& t);

void freeIncomeList(IncomeTransaction*& list, int& count, int& capacity);