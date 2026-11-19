#include "Utils.h"
#include <cstdlib>
bool dateStringValid(const std::string &dateStr) {
    if (dateStr.size() != 10 || dateStr[2] != '/' || dateStr[5] != '/') {
        return false;
    }
    for (int i = 0; i < 10; i++) {
        if (i == 2 || i == 5) {
            continue;
        }
        if (dateStr[i] < '0' || dateStr[i] > '9') {
            return false;
        }
    }
    return true;
}

bool parsingDate(const std::string &dateStr, date &d) {
    if (!dateStringValid(dateStr)) {
        return false;
    }

    date parsed{};
    parsed.day = std::stoi(dateStr.substr(0, 2));
    parsed.month = std::stoi(dateStr.substr(3, 2));
    parsed.year = std::stoi(dateStr.substr(6, 4));
    if (!dateValid(parsed)) {
        return false;
    }

    d = parsed;
    return true;
}
bool leapYearValid(int year){
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    }
    return false;
}

bool dateValid(const date &d){
    if (d.year < 0) {
        return false;
    }
    if (d.month < 1 || d.month > 12) {
        return false;
    }
    if (d.day < 1 || d.day > 31) {
        return false;
    }
    if (d.month == 2) {
        if (leapYearValid(d.year)) {
            return d.day <= 29;
        } else {
            return d.day <= 28;
        }
    }
    if (d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11) {
        return d.day <= 30;
    }
    return true;
}

int cmpDate(const date &d1, const date &d2){
    if (d1.year == d2.year && d1.month == d2.month && d1.day == d2.day) {
        return 0;
    }
    
    if (d1.year < d2.year || 
        (d1.year == d2.year && d1.month < d2.month) || 
        (d1.year == d2.year && d1.month == d2.month && d1.day < d2.day)) {
        return -1;
    }
    
    return 1;
}

namespace ConsoleUtils {
    void clearScreen() {
        #ifdef _WIN32
            std::system("cls");
        #else
            std::system("clear");
        #endif
    }

    void pauseScreen() {
        std::cout << "\nPress Enter to return to Main Dashboard...";
        std::cin.ignore(10000, '\n');
        std::cin.get();
    }

    int getValidChoice() {
        int choice;
        while (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input! Please enter a number: ";
        }
        return choice;
    }
}