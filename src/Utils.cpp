#include "Utils.h"

bool dateStringValid(const std::string &dateStr) {
    if (dateStr.length() != 10 || dateStr[2] != '/' || dateStr[5] != '/') {
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
        std::cout << "Invalid date format. Please use DD/MM/YYYY." << std::endl;
        return false;
    }
    d.day = (dateStr[0] - '0') * 10 + (dateStr[1] - '0');
    d.month = (dateStr[3] - '0') * 10 + (dateStr[4] - '0');
    d.year = (dateStr[6] - '0') * 1000 + (dateStr[7] - '0') * 100 + (dateStr[8] - '0') * 10 + (dateStr[9] - '0');
    return true;
}

bool leapYearValid(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            return year % 400 == 0;
        }
        return true;
    }
    return false;
}

bool dateValid(const date &d) {
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
        }
        return d.day <= 28;
    }
    if (d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11) {
        return d.day <= 30;
    }
    return true;
}

int cmpDate(const date &d1, const date &d2) {
    if (d1.year != d2.year) {
        return d1.year < d2.year ? -1 : 1;
    }
    if (d1.month != d2.month) {
        return d1.month < d2.month ? -1 : 1;
    }
    if (d1.day != d2.day) {
        return d1.day < d2.day ? -1 : 1;
    }
    return 0;
}