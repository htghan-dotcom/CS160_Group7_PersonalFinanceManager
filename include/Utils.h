#pragma once

#include <iostream>
#include <string>

struct date {
    int day, month, year;
};

void parsingDate(const std::string &dateStr, date &d);

bool leapYearValid(int year);

bool dateValid(const date &d);

int cmpDate(const date &d1, const date &d2);

