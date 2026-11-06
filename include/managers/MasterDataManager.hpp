#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "models/ExpenseCategory.hpp"
#include "models/IncomeSource.hpp"
struct MasterDataManager{
    private: 

    std::vector<IncomeSource> IncomeSources;
    std::vector<ExpenseCategory> ExpenseCategories;
    bool isIncomeSourceIdExists(int id);
    bool isExpenseCategorydExists(int id);

    public:
    void addIncomeSource();



};