#include "StartMenu.h"

//private--------------------------------

const char* StartMenu::INIT_ADMIN_USER = "admin";
const char* StartMenu::INIT_ADMIN_PASS = "admin";
vector<string> StartMenu::allowedCommands = {"help", "loginasadmin", "loginasemployee", "loginasclient", "exit"};

void StartMenu::authorizeAdmin(){
    string username;
    std::cout << "$ Input username:" << std::endl << ">";
    std::cin >> username;
    if(database.getAdmin().getUsername() != username){
        throw std::logic_error(WRONG_ADMIN_USER);
    }

    string password;
    std::cout << "$ Input password:" << std::endl << ">";
    std::cin >> password;
    if(database.getAdmin().validatePassword(password) == false){
        throw std::logic_error(PASS_WRONG_ERR);
    }
}

void StartMenu::authorizeEmployee(){
    string username;
    std::cout << "$ Input username:" << std::endl << ">";
    std::cin >> username;
    Employee& employee = database.getEmployeeByUsername(username);

    string password;
    std::cout << "$ Input password:" << std::endl << ">";
    std::cin >> password;
    if(employee.validatePassword(password) == false){
        throw std::logic_error(PASS_WRONG_ERR);
    }
}

BankAccount* StartMenu::authorizeClient(){
    string cardNumber;
    std::cout << "$ Input card number:" << std::endl << ">";
    std::cin >> cardNumber;
    Client& client = database.getClientByCard(cardNumber);
    Card& card = client.getCard(cardNumber);

    string PIN;
    std::cout << "$ Input PIN:" << std::endl << ">";
    std::cin >> PIN;
    if(card.validatePIN(PIN) == false){
        throw std::logic_error(PIN_WRONG_ERR);
    }

    return &client.getAccountByCard(cardNumber);
}

//public---------------------------------

StartMenu::StartMenu(): database(), mainMenu(nullptr){
    if(!database.hasAdmin()){
        database.setAdmin(Admin(INIT_ADMIN_USER, INIT_ADMIN_PASS));
    }
}

StartMenu::~StartMenu(){
    delete mainMenu;
}

void StartMenu::run(){
    printWelcomeMessage();
    printHelpMessage();

    string command;
    while(!exiting){
        std::cout << ">";
        std::cin >> command;
        analyzeCommand(strToLower(command));

        if(mainMenu != nullptr){
            printSuccessMessage(LOGIN_SUCCESS_MESSAGE);
            mainMenu -> run();
            mainMenu = nullptr;
            printWelcomeMessage();
            printHelpMessage();
        }
    }

    printExitMessage();
}

void StartMenu::analyzeCommand(const string& command){
    if(command == allowedCommands[0]){
        printHelp();
    }else if(command == allowedCommands[1]){
        loginAsAdmin();
    }else if(command == allowedCommands[2]){
        loginAsEmployee();
    }else if(command == allowedCommands[3]){
        loginAsClient();
    }else if(command == allowedCommands[4]){
        exit();
    }else{
        printInvalidCommandMessage();
        printHelpMessage();
    }
}

void StartMenu::printHelp(){
    std::cout << "$ \"loginAsAdmin\": login as bank administrator" << std::endl;
    std::cout << "$ \"loginAsEmployee\": login as bank employee" << std::endl;
    std::cout << "$ \"loginAsClient\": login as bank client" << std::endl;
    std::cout << "$ \"exit\": exit bank system" << std::endl;
}

void StartMenu::loginAsAdmin(){
    try{
        authorizeAdmin();
        mainMenu = new AdminMenu(&database);
    }catch(std::logic_error e){
        printFailureMessage(e.what());
    }
}

void StartMenu::loginAsEmployee(){
   try{
        authorizeEmployee();
        mainMenu = new EmployeeMenu(&database);
    }catch(std::logic_error e){
        printFailureMessage(e.what());
    }
}

void StartMenu::loginAsClient(){
   try{
        BankAccount* account = authorizeClient();
        mainMenu = new ClientMenu(account);
    }catch(std::logic_error e){
        printFailureMessage(e.what());
    }
}
