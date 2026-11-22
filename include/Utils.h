#pragma once

#include <iostream>
#include <string>

struct date {
    int day, month, year;
};
bool dateStringValid(const std::string &dateStr);

bool parsingDate(const std::string &dateStr, date &d);

bool leapYearValid(int year);

bool dateValid(const date &d);

int cmpDate(const date &d1, const date &d2);

namespace ConsoleUtils{
    void clearScreen();
    void pauseScreen();
    int getValidChoice();
}