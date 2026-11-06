#include "Utils.h"

bool dateStringValid(const std::string &dateStr) {
    if (dateStr.length() != 10 || dateStr[2] != '/' || dateStr[5] != '/') {
        return false;
    }
    
    return true;
}
void parsingDate(const std::string &dateStr, date &d){
    if (!dateStringValid(dateStr)) {
        std::cout << "Invalid date format. Please use DD/MM/YYYY." << std::endl;
        return;
    }
    
    d.day = std::stoi(dateStr.substr(0, 2));
    d.month = std::stoi(dateStr.substr(3, 2));
    d.year = std::stoi(dateStr.substr(6, 4));
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