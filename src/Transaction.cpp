#include "Transaction.h"
#include <cstdio>

static char* copyString(const char* src) {
    if (src == nullptr) {
        src = "";
    }
    char* dst = new char[strlen(src) + 1];
    strcpy(dst, src);
    return dst;
}

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
                  const char* date, int sourceId,
                  long long amount, int walletId,
                  const char* description) {

    if (amount <= 0 || date == nullptr || date[0] == '\0' || sourceId <= 0 || walletId <= 0) {
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
    list[count].date = copyString(date);
    list[count].sourceId = sourceId;
    list[count].amount = amount;
    list[count].walletId = walletId;
    list[count].description = copyString(description);
    ++count;

    return true;
}

char* incomeToString(const IncomeTransaction& t) {
    const char* fmt = "[ID: %d] Date: %s | SourceID: %d | WalletID: %d | Amount: +%lld | Note: %s";
    const char* dateStr = (t.date != nullptr) ? t.date : "";
    const char* noteStr = (t.description != nullptr) ? t.description : "";

    int len = snprintf(nullptr, 0, fmt, t.id, dateStr, t.sourceId, t.walletId, t.amount, noteStr);
    char* result = new char[len + 1];
    snprintf(result, len + 1, fmt, t.id, dateStr, t.sourceId, t.walletId, t.amount, noteStr);
    return result;
}

void freeIncomeList(IncomeTransaction*& list, int& count, int& capacity) {
    for (int i = 0; i < count; ++i) {
        delete[] list[i].date;
        delete[] list[i].description;
    }
    delete[] list;
    list = nullptr;
    count = 0;
    capacity = 0;
}