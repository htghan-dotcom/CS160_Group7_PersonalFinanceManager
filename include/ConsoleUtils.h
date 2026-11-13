#pragma once
#include <iostream>
#include <cstdlib>

namespace ConsoleUtils {

    // 1. Xóa sạch màn hình Console (tự nhận diện Windows hoặc macOS/Linux)
    inline void clearScreen() {
        #ifdef _WIN32
            std::system("cls");
        #else
            std::system("clear");
        #endif
    }

    // 2. Tạm dừng màn hình để đọc thông báo trước khi quay về Dashboard
    inline void pauseScreen() {
        std::cout << "\nPress Enter to return to Main Dashboard...";
        std::cin.ignore(10000, '\n');
        std::cin.get();
    }

    // 3. Nhập số nguyên an toàn cho Menu (tránh lặp vô tận nếu nhập chữ)
    inline int getValidChoice() {
        int choice;
        while (!(std::cin >> choice)) {
            std::cin.clear();             // Xóa trạng thái lỗi của cin
            std::cin.ignore(10000, '\n'); // Dọn sạch ký tự rác trong bộ nhớ đệm
            std::cout << "Invalid input! Please enter a number: ";
        }
        return choice;
    }

}