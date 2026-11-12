#include "Transaction.h"
#include <sstream>

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

    IncomeTransaction tx;
    tx.id = nextIncomeId(list, count);
    tx.date = date;
    tx.sourceId = sourceId;
    tx.amount = amount;
    tx.walletId = walletId;
    tx.description = description;

    list[count] = tx;
    ++count;

    return true;
}

std::string incomeToString(const IncomeTransaction& t) {
    std::ostringstream oss;
    oss << "[ID: " << t.id << "] "
        << "Date: " << t.date
        << " | SourceID: " << t.sourceId
        << " | WalletID: " << t.walletId
        << " | Amount: +" << t.amount
        << " | Note: " << t.description;
    return oss.str();
}

void freeIncomeList(IncomeTransaction*& list, int& count, int& capacity) {
    delete[] list;
    list = nullptr;
    count = 0;
    capacity = 0;
}