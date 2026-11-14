#pragma once
#include <iostream>
#include <cstdlib>

namespace ConsoleUtils {
    inline void clearScreen() {
        #ifdef _WIN32
            std::system("cls");
        #else
            std::system("clear");
        #endif
    }

    inline void pauseScreen() {
        std::cout << "\nPress Enter to return to Main Dashboard...";
        std::cin.ignore(10000, '\n');
        std::cin.get();
    }
    inline int getValidChoice() {
        int choice;
        while (!(std::cin >> choice)) {
            std::cin.clear();             
            std::cin.ignore(10000, '\n'); 
            std::cout << "Invalid input! Please enter a number: ";
        }
        return choice;
    }

}