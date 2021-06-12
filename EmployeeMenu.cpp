#include "EmployeeMenu.h"

//private-----------------------------
vector<string> EmployeeMenu::allowedCommands = {"help", "addnewclient", "removeclient", "createnewaccount", 
                                  "addnewcard", "removeaccount", "removecard", 
                                  "clientsreport", "individualreport", "logout"};

Client EmployeeMenu::inputNewClInfo(){
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

    Client newClient(EGN, firstName, middleName, lastName, Date(day,month, year), phoneNumber, address);

    return newClient;   
}

string EmployeeMenu::inputRemoveClInfo(){
    string EGN;
    std::cout << "$ Input EGN:" << std::endl << ">";
    std::cin >> EGN;

    return EGN;
}

void EmployeeMenu::createAccountInfo(){
    string EGN;
    std::cout << "$ Input EGN: " << std::endl << ">";
    std::cin >> EGN;

    double initAmount;
    std::cout << "$ Input initial amount: " << std::endl << ">";
    std::cin >> initAmount;

    Client& client = database->getClientByEGN(EGN);
    string newIBAN = client.generateIBAN();

    client.addAccount(BankAccount(newIBAN, initAmount));
}

void EmployeeMenu::removeAccountInfo(){
    string EGN;
    std::cout << "$ Input EGN: " << std::endl << ">";
    std::cin >> EGN;

    Client& client = database->getClientByEGN(EGN);

    string IBAN;
    std::cout << "$ Input IBAN: " << std::endl << ">";
    std::cin >> IBAN;


    client.removeAccount(IBAN);
}

void EmployeeMenu::createCardInfo(){
    string EGN;
    std::cout << "$ Input EGN: " << std::endl << ">";
    std::cin >> EGN;

    Client& client = database->getClientByEGN(EGN);

    string IBAN;
    std::cout << "$ Input IBAN: " << std::endl << ">";
    std::cin >> IBAN;

    string newCardNumber = client.generateCardNumber();
    string newPIN = Card::generateRandPIN();

    client.addCard(IBAN, Card(newCardNumber, newPIN));
}

void EmployeeMenu::removeCardInfo(){
    string EGN;
    std::cout << "$ Input EGN: " << std::endl << ">";
    std::cin >> EGN;

    Client& client = database->getClientByEGN(EGN);
    
    string IBAN;
    std::cout << "$ Input IBAN: " << std::endl << ">";
    std::cin >> IBAN;

    string cardNumber;
    std::cout << "$ Input card number: " << std::endl << ">";
    std::cin >> cardNumber;

    client.removeCard(IBAN, cardNumber);
}

string EmployeeMenu::inputReportInfo(){
    string EGN;
    std::cout << "$ Input EGN: " << std::endl << ">";
    std::cin >> EGN;

    return EGN;
}

//public------------------------------

EmployeeMenu::EmployeeMenu(BankDatabase* database): database(database){}
    
void EmployeeMenu::analyzeCommand(const string& command){

    if(command == allowedCommands[0]){
        printHelp();
    }else if(command == allowedCommands[1]){
        addNewClient();
    }else if(command == allowedCommands[2]){
        removeClient();
    }else if(command == allowedCommands[3]){
        createNewAccount();
    }else if(command == allowedCommands[4]){
        addNewCard();
    }else if(command == allowedCommands[5]){
        removeAccount();
    }else if(command == allowedCommands[6]){
        removeCard();
    }else if(command == allowedCommands[7]){
        printClientsReport();
    }else if(command == allowedCommands[8]){
        printIndividualReport();
    }else if(command == allowedCommands[9]){
        exit();
    }else{
        printInvalidCommandMessage();
        printHelpMessage();
    }
}

void EmployeeMenu::printHelp(){
    std::cout << "$ \"addNewClient\": add a new client" << std::endl;
    std::cout << "$ \"removeClient\": remove an existing client" << std::endl;
    std::cout << "$ \"createNewAccount\": create a new account for a client" << std::endl;
    std::cout << "$ \"addNewCard\": add a new card to a client's account" << std::endl;
    std::cout << "$ \"removeAccount\": remove client's account" << std::endl;
    std::cout << "$ \"removeCard\": remove card from a client's account" << std::endl;
    std::cout << "$ \"clientsReport\": get report for all of the bank's clients" << std::endl;
    std::cout << "$ \"individualReport\": get report for a single client" << std::endl;
    std::cout << "$ \"logout\": logout from your account" << std::endl;
}

void EmployeeMenu::addNewClient(){
    try{
        Client newClient = inputNewClInfo();
        database->addClient(newClient);
        printSuccessMessage(NEW_CL_SUCCESS);
    }catch(std::logic_error e){
        printFailureMessage(e.what());
    }
}

void EmployeeMenu::removeClient(){
    try{
        string EGN = inputRemoveClInfo();
        database->removeClient(EGN);
        printSuccessMessage(REMOVE_CL_SUCCESS);
    }catch(std::logic_error e){
        printFailureMessage(e.what());
    }
}

void EmployeeMenu::createNewAccount(){
    try{
        createAccountInfo();
        printSuccessMessage(NEW_ACCOUNT_SUCCESS);
    }catch(std::logic_error e){
        printFailureMessage(e.what());
    }
}

void EmployeeMenu::removeAccount(){
    try{
        removeAccountInfo();
        printSuccessMessage(REMOVE_ACCOUNT_SUCCESS);
    }catch(std::logic_error e){
        printFailureMessage(e.what());
    }
}

void EmployeeMenu::addNewCard(){
    try{
        createCardInfo();
        printSuccessMessage(NEW_CARD_SUCCESS);
    }catch(std::logic_error e){
        printFailureMessage(e.what());
    }
}

void EmployeeMenu::removeCard(){
    try{
        removeCardInfo();
        printSuccessMessage(REMOVE_CARD_SUCCESS);
    }catch(std::logic_error e){
        printFailureMessage(e.what());
    }
}

void EmployeeMenu::printClientsReport(){
    database->printClientsReport();
}

void EmployeeMenu::printIndividualReport(){
    try{
        string EGN = inputReportInfo();
        database->printIndividualReport(EGN);
    }catch(std::logic_error e){
        printFailureMessage(e.what());
    }
}