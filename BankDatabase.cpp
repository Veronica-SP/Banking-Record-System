#include "BankDatabase.h"

//private----------------------------

const char* BankDatabase::ADMIN_FILENAME = "admin.txt";
const char* BankDatabase::EMPLOYEES_FILENAME = "employees.txt";
const char* BankDatabase::CLIENTS_FILENAME = "clients.txt";

void BankDatabase::copyDatabase(const BankDatabase& other){
    admin = nullptr;
    employees = other.employees;
    clients = other.clients;

    if(other.admin != nullptr){
        admin = new Admin(*other.admin);
    }
}

//public----------------------------

BankDatabase::BankDatabase(): admin(nullptr){
    deserializeDatabase();
}

BankDatabase::BankDatabase(const BankDatabase& other){
    copyDatabase(other);
}

BankDatabase& BankDatabase::operator=(const BankDatabase& other){
    if(this != &other){
        delete admin;
        copyDatabase(other);
    }

    return *this;
}

BankDatabase::~BankDatabase(){
    serializeDatabase();
    delete admin;
}

bool BankDatabase::hasAdmin() const{
    return admin != nullptr;
}

void BankDatabase::setAdmin(const Admin& admin){
    this->admin = new Admin(admin);
}

Admin& BankDatabase::getAdmin(){
    if(admin == nullptr){
        throw std::logic_error(NO_ADMIN_ERR);
    }
    return *admin;
}

Employee& BankDatabase::getEmployeeByEGN(const string& EGN){   
    try{
        return getItemInCollection(employees, EGN);
    }catch(std::logic_error){
        throw std::logic_error(NO_SUCH_EMPLOYEE_EGN_ERR);
    }
}

Employee& BankDatabase::getEmployeeByUsername(const string& username){
   for(int i = 0; i < employees.size(); i++){
        if(username == employees[i].getUsername()){
            return employees[i];
        }
    }

    throw std::logic_error(NO_SUCH_EMPLOYEE_USER_ERR);
}

Client& BankDatabase::getClientByEGN(const string& EGN){
    try{
        return getItemInCollection(clients, EGN);
    }catch(std::logic_error){
        throw std::logic_error(NO_SUCH_CLIENT_EGN_ERR);
    }
}

Client& BankDatabase::getClientByCard(const string& cardNumber){
    if(cardNumber.length() < Card::MIN_CARD_NUM_LEN){
        throw std::invalid_argument(CARD_NUM_LEN_ERR);
    }

    string clientEGNLast4Digits = cardNumber.substr(2, 4);

    for (int i = 0; i < clients.size(); i++)
    {
        Client& client = clients[i];
        if(client.getEGN().substr(6) == clientEGNLast4Digits){
            return client;
        }
    }

    throw std::logic_error(NO_SUCH_CLIENT_CARD_ERR);
}

void BankDatabase::addEmployee(const Employee& newEmployee){
    try{
        getEmployeeByEGN(newEmployee.getEGN());
    }catch(std::logic_error){
        try{
            getEmployeeByUsername(newEmployee.getUsername());
        }catch(std::logic_error){
            employees.push_back(newEmployee);
            return;
        }
    }
    throw std::logic_error(EXISTING_EMPLOYEE_EGN_ERR);
}

void BankDatabase::removeEmployee(const string& EGN){
    try{
        removeItemFromCollection(employees, EGN);
    }catch(std::logic_error){
        throw std::logic_error(NO_SUCH_EMPLOYEE_EGN_ERR);
    }
}

void BankDatabase::addClient(const Client& newClient){
    try{
        getClientByEGN(newClient.getEGN());
    }catch(std::logic_error){
        clients.push_back(newClient);
        return;
    }
    throw std::logic_error(EXISTING_CLIENT_ERR);
}


void BankDatabase::removeClient(const string& EGN){
    try{
        removeItemFromCollection(clients, EGN);
    }catch(std::logic_error){
        throw std::logic_error(NO_SUCH_CLIENT_EGN_ERR);
    }
}

void BankDatabase::printClientsReport() const{
    for (int i = 0; i < clients.size(); i++)
    {
        std::cout << clients[i] << std::endl;
    }
}

void BankDatabase::printIndividualReport(const string& EGN){
    Client& client = getClientByEGN(EGN);
    std::cout << client << std::endl;
}

void BankDatabase::serializeDatabase() const{
    std::ofstream adminOut(ADMIN_FILENAME);
    if(!adminOut){
        throw std::runtime_error(ADMIN_FILE_ERR);
    }
    if(admin != nullptr){
        (*admin).serialize(adminOut);
    }
    adminOut.close();

    std::ofstream empOut(EMPLOYEES_FILENAME);
    if(!empOut){
        throw std::runtime_error(EMPLOYEE_FILE_ERR);
    }
    serializeColl(empOut, employees, "\n");
    empOut.close();

    std::ofstream clOut(CLIENTS_FILENAME);
    if(!clOut){
        throw std::runtime_error(CLIENT_FILE_ERR);
    }
    serializeColl(clOut, clients, "\n");
    clOut.close();
}

void BankDatabase::deserializeDatabase(){
    std::ifstream adminIn(ADMIN_FILENAME);
    if(adminIn && adminIn.peek() != EOF){
        admin = new Admin();
        (*admin).deserialize(adminIn);
    }
    adminIn.close();

    std::ifstream empIn(EMPLOYEES_FILENAME);
    if(empIn){
        deserializeColl(empIn, employees);
    }
    empIn.close();

    std::ifstream clIn(CLIENTS_FILENAME);
    if(clIn){
        deserializeColl(clIn, clients);
    }
    clIn.close();
}