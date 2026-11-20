#pragma once

#include <iostream>
#include <cstring>

struct IncomeTransaction {
    int id = 0;
    char *date = nullptr;
    int sourceId = 0;
    long long amount = 0;
    int walletId = 0;
    char *description = nullptr;
};

int nextIncomeId(const IncomeTransaction* list, int count);

bool recordIncome(IncomeTransaction*& list, int& count, int& capacity,
                  const char* date, int sourceId,
                  long long amount, int walletId,
                  const char* description);

char* incomeToString(const IncomeTransaction& t);

void freeIncomeList(IncomeTransaction*& list, int& count, int& capacity);