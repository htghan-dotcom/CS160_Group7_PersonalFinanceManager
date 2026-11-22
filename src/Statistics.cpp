#include "Statistics.h"

long long totalIncomeRange(
    const IncomeTransaction* incomeList,
    int incomeCount,
    const std::string& dateStart,
    const std::string& dateEnd,
    int walletId, int sourceId
) {
    if (incomeList == nullptr) {
        std::cout << "Invalid income list.\n";
        return -1;
    }

    date start{}, end{};
    if (!parsingDate(dateStart, start) ||
        !parsingDate(dateEnd, end)) {
        std::cout << "Invalid start or end date.\n";
        return -1;
    }
    if (cmpDate(start, end) > 0) {
        std::cout << "Invalid date range.\n";
        return -1;
    }

    long long total = 0;
    for (int i = 0; i < incomeCount; i++) {
        const IncomeTransaction& data = incomeList[i];

        bool matchesWallet = walletId == -1 || data.walletId == walletId;
        bool matchesSource = sourceId == -1 || data.sourceId == sourceId;
        if (!matchesWallet || !matchesSource) {
            continue;
        }

        date d{};
        if (!parsingDate(data.date, d)) {
            std::cout << "Invalid income transaction date.\n";
            return -1;
        }

        if (cmpDate(start, d) <= 0 &&
            cmpDate(d, end) <= 0) {
            total += data.amount;
        }
    }
    return total;
}

void annualOverview(
    const IncomeTransaction* incomeList,
    int incomeCount,
    int year
) {
    if (year < 1 || year > 9999) {
        std::cout << "Invalid year.\n";
        return;
    }

    std::string yearText = std::to_string(year);
    yearText = std::string(4 - yearText.size(), '0') + yearText;
    long long income = totalIncomeRange(
        incomeList, incomeCount,
        "01/01/" + yearText, "31/12/" + yearText
    );
    if (income == -1) {
        return;
    }

    std::cout << "Annual overview for " << year << ":\n";
    std::cout << "Total income: " << income << '\n';
}

void annualIncomeBreakdown(
    const IncomeTransaction* incomeList, 
    int incomeCount,
    const IncomeSource* incomeSources, 
    int sourceCount,
    int year
){
    if (year < 1 || year > 9999 || sourceCount < 0 || 
        incomeList == nullptr || incomeSources == nullptr) {
        std::cout << "Invalid annual income breakdown input.\n";
        return;
    }

    std::string yearText = std::to_string(year);
    yearText = std::string(4 - yearText.size(), '0') + yearText;
    std::string dateStart = "01/01/" + yearText;
    std::string dateEnd = "31/12/" + yearText;

    std::cout << "Income breakdown for " << year << ":\n";
    for (int i = 0; i < sourceCount; i++) {
        long long total = totalIncomeRange(
            incomeList, incomeCount, dateStart, dateEnd,
            -1, incomeSources[i].sourceID
        );
        if (total == -1) {
            return;
        }
        std::cout << incomeSources[i].sourceName << ": " << total << '\n';
    }
}
void walletIncomeOverview(
    const IncomeTransaction* incomeList,
    int incomeCount,
    const Wallet& wallet,
    const std::string& dateStart,
    const std::string& dateEnd
) {
    if (wallet.id <= 0) {
        std::cout << "Invalid wallet ID.\n";
        return;
    }

    long long income = totalIncomeRange(
        incomeList, incomeCount, dateStart, dateEnd, wallet.id
    );
    if (income == -1) {
        return;
    }

    std::cout << "Wallet: " << wallet.name << " (ID: " << wallet.id << ")\n";
    std::cout << "Period: " << dateStart << " - " << dateEnd << '\n';
    std::cout << "Total income: " << income << '\n';
}