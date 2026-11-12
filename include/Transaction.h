#pragma once

#include <iostream>
#include <string>
#include <vector>

struct IncomeTransaction{
    std::string date, id, sourceId;;
    int sourceId;
    long long amount;
    int walletId;
    std::string description;
};

int nextIncomeId(const std::vector<IncomeTransaction> &list);

bool recordIncome(std::vector<IncomeTransaction> &list, const std::string &date, int sourceId, long long amount, int walletId, const std::string &description);

std::string incomeToString(const IncomeTransaction &t);