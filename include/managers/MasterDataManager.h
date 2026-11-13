#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "models/ExpenseCategory.h"
#include "models/IncomeSource.h"
#include <iomanip>
struct MasterDataManager{
    private: 

    std::vector<IncomeSource> IncomeSources;
    std::vector<ExpenseCategory> ExpenseCategories;
    bool isIncomeSourceIdExists(int id);
    bool isExpenseCategoryExists(int id);

    public:
    void addIncomeSource();
    void addExpenseCategory();
    void displayIncomeSources() const;
    void displayExpenseCategories() const;


};