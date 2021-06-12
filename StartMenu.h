#ifndef STARTMENU_H
#define STARTMENU_H

#include "AdminMenu.h"
#include "EmployeeMenu.h"
#include "ClientMenu.h"

class StartMenu: public Menu{
private:
    BankDatabase database;
    Menu* mainMenu;

    //static fields
    static const char* INIT_ADMIN_USER;
    static const char* INIT_ADMIN_PASS;
    static vector<string> allowedCommands;

    void authorizeAdmin();
    void authorizeEmployee();
    BankAccount* authorizeClient();

    //non-copyable
    StartMenu(const StartMenu&) = delete;
    StartMenu& operator=(const StartMenu&) = delete;

    virtual void analyzeCommand(const string& command) override;
    virtual void printHelp() override;

    //actions
    void loginAsAdmin();
    void loginAsEmployee();
    void loginAsClient();

public:
    StartMenu();
    ~StartMenu();

    virtual void run() override;
};

#endif