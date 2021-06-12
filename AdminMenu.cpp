#include "AdminMenu.h"

//private---------------------------------

vector<string> AdminMenu::allowedCommands = {"help", "addnewemployee", "removeemployee", "logout"};

Employee AdminMenu::inputNewEmpInfo(){
    string username;
    std::cout << "$ Input username: " << std::endl << ">";
    std::cin >> username;

    string password;
    std::cout << "$ Input password: " << std::endl << ">";
    std::cin >> password;

    string EGN;
    std::cout << "$ Input EGN: " << std::endl << ">";
    std::cin >> EGN;

    string firstName;
    std::cout << "$ Input first name: " << std::endl << ">";
    std::cin >> firstName;

    string middleName;
    std::cout << "$ Input middle name: " << std::endl << ">";
    std::cin >> middleName;

    string lastName;
    std::cout << "$ Input last name: " << std::endl <<">";
    std::cin >> lastName;

    int day,month,year;
    std::cout << "$ Input date of birth(DD MM YYYY): " << std::endl << ">";
    std::cin >> day >> month >> year;

    string phoneNumber;
    std::cout << "$ Input phone number: " << std::endl << ">";
    std::cin >> phoneNumber;

    string address;
    std::cout << "$ Input address: " << std::endl << ">";
    std::cin.get();
    getline(std::cin, address);
    address.insert(0, "\"");
    address += "\"";

    Employee newEmp(username, password, EGN, firstName, middleName, lastName, Date(day,month, year), phoneNumber, address);

    return newEmp;   
}

string AdminMenu::inputRemoveEmpInfo(){
    string EGN;
    std::cout << "$ Input EGN:" << std::endl << ">";
    std::cin >> EGN;

    return EGN;

}

//public----------------------------------

AdminMenu::AdminMenu(BankDatabase* database): database(database){}

void AdminMenu::analyzeCommand(const string& command){
    if(command == allowedCommands[0]){
        printHelp();
    }else if(command == allowedCommands[1]){
        addNewEmployee();
    }else if(command == allowedCommands[2]){
        removeEmployee();
    }else if(command == allowedCommands[3]){
        exit();
    }else{
        printInvalidCommandMessage();
        printHelpMessage();
    }
}

void AdminMenu::printHelp(){
    std::cout << "$ \"addNewEmployee\": add a new employee" << std::endl;
    std::cout << "$ \"removeEmployee\": remove an existing employee" << std::endl;
    std::cout << "$ \"logout\": logout from your account" << std::endl;
}

void AdminMenu::addNewEmployee(){
    try{
        Employee newEmp = inputNewEmpInfo();
        database->addEmployee(newEmp);
        printSuccessMessage(NEW_EMP_SUCCESS);
    }catch(std::logic_error e){
        printFailureMessage(e.what());
    }
}

void AdminMenu::removeEmployee(){
    try{
        string EGN = inputRemoveEmpInfo();
        database->removeEmployee(EGN);
        printSuccessMessage(REMOVE_EMP_SUCCESS);
    }catch(std::logic_error e){
        printFailureMessage(e.what());
    }
}