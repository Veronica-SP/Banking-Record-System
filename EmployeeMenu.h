#ifndef EMPLOYEEMENU_H
#define EMPLOYEEMENU_H

#include "Menu.h"

class EmployeeMenu: public Menu{
private:
    BankDatabase* database;

    //static fields
    static vector<string> allowedCommands;

    Client inputNewClInfo();
    string inputRemoveClInfo();

    void createAccountInfo();
    void removeAccountInfo();
    
    void createCardInfo();
    void removeCardInfo();

    string inputReportInfo();

    void analyzeCommand(const string& command) override;
    void printHelp() override;

    //actions
    void addNewClient();
    void removeClient();

    void createNewAccount();
    void removeAccount();
    
    void addNewCard();
    void removeCard();
    
    void printClientsReport();
    void printIndividualReport();
    
public:
    EmployeeMenu(BankDatabase* database);
};

#endif