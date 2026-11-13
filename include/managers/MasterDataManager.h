#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "models/ExpenseCategory.h"
#include "models/IncomeSource.h"
#include <iomanip>
struct MasterDataManager{
    IncomeSource* incomeSources;
    int incomeCount;
    int incomeCapacity;

    ExpenseCategory* expenseCategories;
    int expenseCount;
    int expenseCapacity;

    MasterDataManager() {
        incomeCapacity = 10;
        incomeCount = 0;
        incomeSources = new IncomeSource[incomeCapacity];

        expenseCapacity = 10;
        expenseCount = 0;
        expenseCategories = new ExpenseCategory[expenseCapacity];
    }

    ~MasterDataManager() {
        delete[] incomeSources;
        delete[] expenseCategories;
    }
    public:
    bool isIncomeSourceIdExists(int id);
    bool isExpenseCategoryExists(int id);
    void resizeIncomeSources();
    void resizeExpenseCategories();
    void addIncomeSource();
    void addExpenseCategory();
    void displayIncomeSources() const;
    void displayExpenseCategories() const;
    void deleteIncomeSource();
    void deleteExpenseCategory();
    void updateIncomeSource();
    void updateExpenseCategory();


};