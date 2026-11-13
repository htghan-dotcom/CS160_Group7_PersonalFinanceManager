#include "managers/MasterDataManager.h"

bool MasterDataManager::isIncomeSourceIdExists(int id){
    //Check if the new sourceID is in the database
    for (int i = 0; i < incomeCount; i++){
        if (incomeSources[i].sourceID == id){
            return true;
        }
    }
    return false;
}

bool MasterDataManager::isExpenseCategoryExists(int id){
    //Check if the new categoryID is in the database
    for (int i = 0; i < expenseCount; i++){
        if (expenseCategories[i].categoryID == id){
            return true;
        }
    }
    return false;
}

void MasterDataManager::resizeIncomeSources() {
    int newCapacity = incomeCapacity * 2;
    IncomeSource* newArray = new IncomeSource[newCapacity]; 

    for (int i = 0; i < incomeCount; ++i) {
        newArray[i] = incomeSources[i]; 
    }

    delete[] incomeSources;          
    incomeSources = newArray;       
    incomeCapacity = newCapacity;    
}

void MasterDataManager::resizeExpenseCategories() {
    int newCapacity = expenseCapacity* 2;
    ExpenseCategory* newArray = new ExpenseCategory[newCapacity]; 

    for (int i = 0; i < expenseCount; ++i) {
        newArray[i] = expenseCategories[i]; 
    }

    delete[] expenseCategories;          
    expenseCategories = newArray;       
    expenseCapacity = newCapacity;    
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

        if (incomeCount == incomeCapacity){
            resizeIncomeSources();
        }
        incomeSources[incomeCount] = IncomeSource(sourceID,name);
        incomeCount++;
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

    if (expenseCount == expenseCapacity){
        resizeExpenseCategories();
    }
    expenseCategories[expenseCount] = ExpenseCategory(categoryID, name);
    //Notify the user that the new expense category is added successfully

    std::cout << "Added Expense Category Successfully!\n";
}

void MasterDataManager::displayIncomeSources() const{

    //Check if the Income Sources List is empty

    if (incomeCount == 0){
        std::cout << "Income Sources List Is Empty!\n";
        return;
    }

    //Print the Income Sources list

    std::cout << "\n========================INCOME SOURCES LIST========================\n";
    std::cout << "\n+----------+------------------------------------------------------+\n";
    std::cout << "| "<<std::left << std::setw(8) << "ID" << " | " << std::setw(52) << "INCOME SOURCE NAME" << " |\n";
    std::cout << "+----------+------------------------------------------------------+\n";

    for (int i = 0; i < incomeCount; i++){
        std::cout << "| "<<std::left << std::setw(8) << incomeSources[i].sourceID << " | " << std::setw(52) << incomeSources[i].sourceName << " |\n";
    }

    std::cout << "+----------+------------------------------------------------------+\n";
    std::cout << "Total: " << incomeCount << " income sources.\n";
}

void MasterDataManager::displayExpenseCategories() const{

    //Check if the Expense Categories List is empty

    if (expenseCount == 0){
        std::cout << "Expense Categories List Is Empty!\n";
        return;
    }

    //Print the Expense Categories list

    std::cout << "\n=====================EXPENSE CATEGORIES LIST======================\n";
    std::cout << "\n+----------+-----------------------------------------------------+\n";
    std::cout << "| "<<std::left << std::setw(8) << "ID" << " | " << std::setw(51) << "EXPENSE CATEGORY NAME" << " |\n";
    std::cout << "+----------+-----------------------------------------------------+\n";

    for (int i = 0; i < expenseCount; i++){
        std::cout << "| "<<std::left << std::setw(8) << expenseCategories[i].categoryID << " | " << std::setw(51) << expenseCategories[i].categoryName << " |\n";
    }

    std::cout << "+----------+-----------------------------------------------------+\n";
    std::cout << "Total: " << expenseCount << " expense categories.\n";
}

void MasterDataManager::deleteIncomeSource(){
    std::cout << "\nEnter Income Source ID to delete: ";
    int id;
    if (!(std::cin >> id)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid ID format!\n";
        return;
    }

    int foundIndex = -1;
    for (int i = 0; i < incomeCount; ++i) {
        if (incomeSources[i].sourceID == id) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        std::cout << "ID not found!\n";
        return;
    }

    for (int i = foundIndex; i < incomeCount - 1; ++i) {
        incomeSources[i] = incomeSources[i + 1];
    }

    incomeCount--;
    std::cout << "Deleted Income Source Successfully!\n";
}

void MasterDataManager::deleteExpenseCategory() {
    std::cout << "\nEnter Expense Category ID to delete: ";
    int id;
    while (!(std::cin >> id) || id < 0) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid Value!. Re-enter Expense Category ID: ";
    }

    int foundIndex = -1;
    for (int i = 0; i < expenseCount; ++i) {
        if (expenseCategories[i].categoryID == id) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        std::cout << "ID not found!\n";
        return;
    }

    for (int i = foundIndex; i < expenseCount - 1; ++i) {
        expenseCategories[i] = expenseCategories[i + 1];
    }

    expenseCount--;
    std::cout << "Deleted Expense Category Successfully!\n";
}

void MasterDataManager::updateIncomeSource() {
    std::cout << "\nEnter Income Source ID to update: ";
    int id;
    while (!(std::cin >> id) || id < 0) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid Value!. Re-enter Income Source ID: ";
    }

    for (int i = 0; i < incomeCount; ++i) {
        if (incomeSources[i].sourceID == id) {
            std::cin.ignore(10000, '\n'); 
            std::cout << "Enter New Income Source Name: ";
            std::getline(std::cin, incomeSources[i].sourceName);
            std::cout << "Updated Income Source Successfully!\n";
            return;
        }
    }

    std::cout << "ID not found!\n";
}

void MasterDataManager::updateExpenseCategory() {
    std::cout << "\nEnter Expense Category ID to update: ";
    int id;
    while (!(std::cin >> id) || id < 0) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid Value!. Re-enter Expense Category ID: ";
    }

    for (int i = 0; i < expenseCount; ++i) {
        if (expenseCategories[i].categoryID == id) {
            std::cin.ignore(10000, '\n');
            std::cout << "Enter New Expense Category Name: ";
            std::getline(std::cin, expenseCategories[i].categoryName);
            std::cout << "Updated Expense Category Successfully!\n";
            return;
        }
    }

    std::cout << "ID not found!\n";
}