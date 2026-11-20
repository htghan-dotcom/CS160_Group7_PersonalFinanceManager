#pragma once

#include <iostream>
#include <cstring>

struct date {
    int day, month, year;
};

bool dateStringValid(const char *dateStr);

void parsingDate(const char *dateStr, date &d);

bool leapYearValid(int year);

bool dateValid(const date &d);

int cmpDate(const date &d1, const date &d2);