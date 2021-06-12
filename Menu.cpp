#include "Menu.h"

//protected-------------------------

Menu::Menu(): exiting(false){}

//public----------------------------

void Menu::run(){
    printHelpMessage();

    string command;
    while(!exiting){
        std::cout << ">";
        std::cin >> command;
        analyzeCommand(strToLower(command));
    }

    printLogoutMessage();
}

void Menu::exit(){
    exiting = true;
}

void Menu::printWelcomeMessage(){
    std::cout << WELCOME_MESSAGE << std::endl;
}

void Menu::printHelpMessage(){
    std::cout << HELP_MESSAGE << std::endl;
}

void Menu::printInvalidCommandMessage(){
    std::cout << INVALID_COMMAND_MESSAGE << std::endl;
} 

void Menu::printSuccessMessage(const string& msg){
    std::cout << msg << std::endl;
}

void Menu::printFailureMessage(const string& msg){
    std::cout << msg << std::endl;
}

void Menu::printLogoutMessage(){
    std::cout << LOGOUT_MESSAGE << std::endl;
}

void Menu::printExitMessage(){
    std::cout << SYSTEM_EXIT_MESSAGE << std::endl;
}
