#include "managers/MasterDataManager.h"

bool MasterDataManager::isIncomeSourceIdExists(int id){
    //Check if the new sourceID is in the database
    for (const auto& incomesource : IncomeSources){
        if (incomesource.sourceID == id){
            return true;
        }
    }
    return false;
}

bool MasterDataManager::isExpenseCategoryExists(int id){
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
        //Ask the user to enter the new Source Name

        std::cin.ignore(10000, '\n');
        std::string name;
        std::cout << "Enter New Income Source Name: ";
        std::getline(std::cin, name);

        //Create new income source

        IncomeSource newSource = IncomeSource(sourceID, name);
        IncomeSources.push_back(newSource);

        //Notify the user that the new income source is added successfully

        std::cout << "Added Income Source Successfully!\n";

    }

void MasterDataManager::addExpenseCategory(){

    //Ask the user to enter the new Expense Category ID

    std::cout <<  "\nEnter New Expense Category ID (A Positive Integer): ";
    int categoryID;
    while (!std::cin >> categoryID || categoryID < 0){
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cout << "Invalid Value!. Re-enter New Expense Category ID (A Positive Integer): ";
    }

    //Check if the Expense Category ID exists

    if (isExpenseCategoryExists(categoryID)) {
            std::cout << "ID Exists. Please Re-enter!\n";
            return;
    }

    // Ask the user to enter the new Category Name
    
    std::cin.ignore(10000,'\n');
    std::string name;
    std::cout << "Enter New Expense Category Name: ";
    std::getline(std::cin, name);

    //Create new Expense Category

    ExpenseCategory newCategory = ExpenseCategory(categoryID, name);
    ExpenseCategories.push_back(newCategory);

    //Notify the user that the new expense category is added successfully

    std::cout << "Added Expense Category Successfully!\n";
}

void MasterDataManager::displayIncomeSources() const{

    //Check if the Income Sources List is empty

    if (IncomeSources.empty()){
        std::cout << "Income Sources List Is Empty!\n";
        return;
    }

    //Print the Income Sources list

    std::cout << "\n========================INCOME SOURCES LIST========================\n";
    std::cout << "\n+----------+------------------------------------------------------+\n";
    std::cout << "| "<<std::left << std::setw(8) << "ID" << " | " << std::setw(52) << "INCOME SOURCE NAME" << " |\n";
    std::cout << "+----------+------------------------------------------------------+\n";

    for (const auto& item: IncomeSources){
        std::cout << "| "<<std::left << std::setw(8) << item.sourceID << " | " << std::setw(52) << item.sourceName << " |\n";
    }

    std::cout << "+----------+------------------------------------------------------+\n";
    std::cout << "Total: " << IncomeSources.size() << " income sources.\n";
}

void MasterDataManager::displayExpenseCategories() const{

    //Check if the Expense Categories List is empty

    if (ExpenseCategories.empty()){
        std::cout << "Expense Categories List Is Empty!\n";
        return;
    }

    //Print the Expense Categories list

    std::cout << "\n=====================EXPENSE CATEGORIES LIST======================\n";
    std::cout << "\n+----------+-----------------------------------------------------+\n";
    std::cout << "| "<<std::left << std::setw(8) << "ID" << " | " << std::setw(51) << "EXPENSE CATEGORY NAME" << " |\n";
    std::cout << "+----------+-----------------------------------------------------+\n";

    for (const auto& item: ExpenseCategories){
        std::cout << "| "<<std::left << std::setw(8) << item.categoryID << " | " << std::setw(52) << item.categoryName << " |\n";
    }

    std::cout << "+----------+-----------------------------------------------------+\n";
    std::cout << "Total: " << IncomeSources.size() << " expense categories.\n";
}