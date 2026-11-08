#pragma once
#include <iostream>
#include <string>
struct IncomeSource{
    int sourceID;
    std::string sourceName;

    IncomeSource() : sourceID(0), sourceName(""){}

    IncomeSource(int id, const std::string &name) : sourceID(id), sourceName(name) {}
};
