#pragma once
#include <string>
struct ExpenseCategory{
    int categoryID;
    std::string categoryName;

    ExpenseCategory() : categoryID(0), categoryName("") {}

    ExpenseCategory(int id, const std::string& name) : categoryID(id), categoryName(name) {}
};