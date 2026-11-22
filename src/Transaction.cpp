#include "Transaction.h"

int nextIncomeId(const IncomeTransaction* list, int count) {
    if (list == nullptr || count <= 0) {
        return 1;
    }

    int maxId = 0;
    for (int i = 0; i < count; ++i) {
        if (list[i].id > maxId) {
            maxId = list[i].id;
        }
    }
    return maxId + 1;
}

bool recordIncome(IncomeTransaction*& list, int& count, int& capacity,
                  const std::string& date, int sourceId,
                  long long amount, int walletId,
                  const std::string& description) {

    if (amount <= 0 || date.empty() || sourceId <= 0 || walletId <= 0) {
        return false;
    }

    if (list == nullptr || count >= capacity) {
        int newCapacity = (capacity <= 0) ? 4 : capacity * 2;
        IncomeTransaction* newList = new IncomeTransaction[newCapacity];

        for (int i = 0; i < count; ++i) {
            newList[i] = list[i];
        }

        delete[] list;
        list = newList;
        capacity = newCapacity;
    }

    list[count].id = nextIncomeId(list, count);
    list[count].date = date;
    list[count].sourceId = sourceId;
    list[count].amount = amount;
    list[count].walletId = walletId;
    list[count].description = description;
    ++count;

    return true;
}

std::string incomeToString(const IncomeTransaction& t) {
    return "[ID: " + std::to_string(t.id) +
           "] Date: " + t.date +
           " | SourceID: " + std::to_string(t.sourceId) +
           " | WalletID: " + std::to_string(t.walletId) +
           " | Amount: +" + std::to_string(t.amount) +
           " | Note: " + t.description;
}

void freeIncomeList(IncomeTransaction*& list, int& count, int& capacity) {
    delete[] list;
    list = nullptr;
    count = 0;
    capacity = 0;
}

int nextExpenseId(const ExpenseTransaction* list, int count) {
    if (list == nullptr || count <= 0) {
        return 1;
    }

    int maxId = 0;
    for (int i = 0; i < count; ++i) {
        if (list[i].id > maxId) {
            maxId = list[i].id;
        }
    }
    return maxId + 1;
}

bool recordExpense(ExpenseTransaction*& list, int& count, int& capacity,
                   const std::string& date, int categoryId,
                   long long amount, int walletId,
                   const std::string& description) {

    if (amount <= 0 || date.empty() || categoryId <= 0 || walletId <= 0) {
        return false;
    }

    if (list == nullptr || count >= capacity) {
        int newCapacity = (capacity <= 0) ? 4 : capacity * 2;
        ExpenseTransaction* newList = new ExpenseTransaction[newCapacity];

        for (int i = 0; i < count; ++i) {
            newList[i] = list[i];
        }

        delete[] list;
        list = newList;
        capacity = newCapacity;
    }

    list[count].id = nextExpenseId(list, count);
    list[count].date = date;
    list[count].categoryId = categoryId;
    list[count].amount = amount;
    list[count].walletId = walletId;
    list[count].description = description;
    ++count;

    return true;
}

std::string expenseToString(const ExpenseTransaction& t) {
    return "[ID: " + std::to_string(t.id) +
           "] Date: " + t.date +
           " | CategoryID: " + std::to_string(t.categoryId) +
           " | WalletID: " + std::to_string(t.walletId) +
           " | Amount: -" + std::to_string(t.amount) +
           " | Note: " + t.description;
}

void freeExpenseList(ExpenseTransaction*& list, int& count, int& capacity) {
    delete[] list;
    list = nullptr;
    count = 0;
    capacity = 0;
}