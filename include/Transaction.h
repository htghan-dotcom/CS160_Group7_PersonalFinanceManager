#pragma once

#include <iostream>
#include <string>

struct IncomeTransaction {
    int id = 0;
    std::string date;
    int sourceId = 0;
    long long amount = 0;
    int walletId = 0;
    std::string description;
};

struct ExpenseTransaction {
    int id = 0;
    std::string date;
    int categoryId = 0;
    long long amount = 0;
    int walletId = 0;
    std::string description;
};

int nextIncomeId(const IncomeTransaction* list, int count);

bool recordIncome(IncomeTransaction*& list, int& count, int& capacity,
                  const std::string& date, int sourceId,
                  long long amount, int walletId,
                  const std::string& description);

std::string incomeToString(const IncomeTransaction& t);

void freeIncomeList(IncomeTransaction*& list, int& count, int& capacity);

int nextExpenseId(const ExpenseTransaction* list, int count);

bool recordExpense(ExpenseTransaction*& list, int& count, int& capacity,
                   const std::string& date, int categoryId,
                   long long amount, int walletId,
                   const std::string& description);

std::string expenseToString(const ExpenseTransaction& t);

void freeExpenseList(ExpenseTransaction*& list, int& count, int& capacity);