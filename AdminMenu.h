#ifndef ADMINMENU_H
#define ADMINMENU_H

#include "Menu.h"

class AdminMenu: public Menu{
private:
    BankDatabase* database;

    //static fields
    static vector<string> allowedCommands;

    Employee inputNewEmpInfo();
    string inputRemoveEmpInfo();

    virtual void analyzeCommand(const string& command) override;
    virtual void printHelp() override;

    //actions
    void addNewEmployee();
    void removeEmployee();
    
public:
    AdminMenu(BankDatabase* database);
};

#endif