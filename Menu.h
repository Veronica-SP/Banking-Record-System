#ifndef MENU_H
#define MENU_H

#include "BankDatabase.h"

class Menu{
protected:
    bool exiting;

    Menu(); 
    virtual void analyzeCommand(const string& command) = 0;
    virtual void printHelp() = 0;
    void exit();

    //static methods
    static void printWelcomeMessage();
    static void printHelpMessage();
    static void printInvalidCommandMessage();
    static void printSuccessMessage(const string& msg);
    static void printFailureMessage(const string& msg);
    static void printLogoutMessage();
    static void printExitMessage();
    
public:
    virtual ~Menu() = default;

    virtual void run();
};


#endif