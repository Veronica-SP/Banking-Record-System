#include "ClientMenu.h"

//private------------------------------

vector<string> ClientMenu::allowedCommands = {"help", "deposit", "withdraw", "checkbalance", "logout"};

double ClientMenu::inputTransactionAmount(){
    double amount;
    std::cout << "$ Input amount:" << std::endl << ">";
    std::cin >> amount;

    return amount;
}

//public-------------------------------

ClientMenu::ClientMenu(BankAccount* account): account(account){}

void ClientMenu::analyzeCommand(const string& command){
    if(command == allowedCommands[0]){
        printHelp();
    }else if(command == allowedCommands[1]){
        deposit();
    }else if(command == allowedCommands[2]){
        withdraw();
    }else if(command == allowedCommands[3]){
        printBalance();
    }else if(command == allowedCommands[4]){
        exit();
    }else{
        printInvalidCommandMessage();
        printHelpMessage();
    }
}

void ClientMenu::printHelp(){
    std::cout << "$ \"deposit\": deposit money in your bank account" << std::endl;
    std::cout << "$ \"withdraw\": withdraw money from your bank account" << std::endl;
    std::cout << "$ \"checkBalance\": check your bank account's balance" << std::endl;
    std::cout << "$ \"logout\": logout from your account" << std::endl;
}

void ClientMenu::deposit(){
    try{
        double amount = inputTransactionAmount();
        account->deposit(amount);
        printSuccessMessage(DEPOSIT_SUCCESS);
    }catch(std::logic_error e){
        printFailureMessage(e.what());
    }
}

void ClientMenu::withdraw(){
    try{
        double amount = inputTransactionAmount();
        account->withdraw(amount);
        printSuccessMessage(WITHDRAW_SUCCESS);
    }catch(std::logic_error e){
        printFailureMessage(e.what());
    }
}

void ClientMenu::printBalance(){
    std::cout << account->getBalance() << std::endl;
}