#ifndef CLIENTMENU_H
#define CLIENTMENU_H

#include "Menu.h"

class ClientMenu: public Menu{
private:
    BankAccount* account;

    //static fields
    static vector<string> allowedCommands;

    double inputTransactionAmount();

    void analyzeCommand(const string& command) override;
    void printHelp() override;

    //actions
    void deposit();
    void withdraw();
    void printBalance();

public:
    ClientMenu(BankAccount* account);
};

#endif