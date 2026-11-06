#include "managers/MasterDataManager.hpp"

bool MasterDataManager::isIncomeSourceIdExists(int id){
    //Check if the new sourceID is in the database
    for (const auto& incomesource : IncomeSources){
        if (incomesource.sourceID == id){
            return true;
        }
    }
    return false;
}

bool MasterDataManager::isExpenseCategorydExists(int id){
    //Check if the new categoryID is in the database
    for (const auto& expensecategory : ExpenseCategories){
        if (expensecategory.categoryID == id){
            return true;
        }
    }
    return false;
}

void MasterDataManager::addIncomeSource(){

        //Ask the user to enter the new Income Source ID

        std::cout << "\nEnter New Income Source ID (A Positive Integer): ";
        int sourceID;
        while (!std::cin>>sourceID || sourceID < 0){
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout << "Invalid Value!. Re-enter New Income Source ID (A Positive Integer): ";
        } 

        if (isIncomeSourceIdExists(sourceID)) {
            std::cout << "ID Exists. Please Re-enter!\n";
            return;
        }
        //Ask the user to enter the new sourceName

        std::cin.ignore(10000, '\n');
        std::string name;
        std::cout << "Enter New Income Source Name: ";
        std::getline(std::cin, name);

        //Create new income source
        IncomeSource newSource = IncomeSource(sourceID, name);
        IncomeSources.push_back(newSource);

        //Notify the user that the new income source is added successfully

        std::cout << "Added Income Source Successfully!";

    }