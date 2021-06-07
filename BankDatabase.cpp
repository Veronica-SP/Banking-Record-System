#include "BankDatabase.h"

//private

const char* BankDatabase::ADMIN_FILENAME = "admin.txt";
const char* BankDatabase::EMPLOYEES_FILENAME = "employees.txt";
const char* BankDatabase::CLIENTS_FILENAME = "clients.txt";

void BankDatabase::loadDatabase(){
    std::ifstream adminIn(ADMIN_FILENAME);

    if(adminIn && adminIn.peek() != EOF){
        admin = new Admin();
        adminIn >> *admin;
    }

    adminIn.close();

    std::ifstream empIn(EMPLOYEES_FILENAME);

    if(empIn){
        empIn >> employees;
    }

    empIn.close();

    std::ifstream clIn(CLIENTS_FILENAME);

    if(clIn){
        clIn >> clients;
    }

    clIn.close();

}

void BankDatabase::serializeDatabase(){
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

    serialize(empOut, employees, "\n");

    empOut.close();

    std::ofstream clOut(CLIENTS_FILENAME);

    if(!clOut){
        throw std::runtime_error(CLIENT_FILE_ERR);
    }

    serialize(clOut, clients, "\n");

    clOut.close();
}

void BankDatabase::copyDatabase(const BankDatabase& other){
    admin = nullptr;
    employees = other.employees;
    clients = other.clients;

    if(other.admin != nullptr){
        admin = new Admin(*other.admin);
    }
}

//public

BankDatabase::BankDatabase(): admin(nullptr){
    loadDatabase();
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

void BankDatabase::addEmployee(const Employee& newEmployee){
    try{
        getEmployeeByEGN(newEmployee.getEGN());
        throw std::logic_error(EXISTING_EMPLOYEE_EGN_ERR);
    }catch(std::invalid_argument){
        try{
            getEmployeeByUsername(newEmployee.getUsername());
            throw std::logic_error(EXISTING_EMPLOYEE_USER_ERR);
        }catch(std::invalid_argument){
            employees.push_back(newEmployee);
        }
    }
}

void BankDatabase::removeEmployee(const string& EGN){
    try{
        removeItemFromCollection(employees, EGN);
    }catch(std::invalid_argument){
        throw std::invalid_argument(NO_SUCH_EMPLOYEE_EGN_ERR);
    }
}

void BankDatabase::addClient(const Client& newClient){
    try{
        getClient(newClient.getEGN());
        throw std::logic_error(EXISTING_CLIENT_ERR);
    }catch(std::invalid_argument){
        clients.push_back(newClient);
    }
}

Client& BankDatabase::getClient(const string& EGN){
    try{
        return getItemInCollection(clients, EGN);
    }catch(std::invalid_argument){
        throw std::invalid_argument(NO_SUCH_CLIENT_ERR);
    }
}

Employee& BankDatabase::getEmployeeByEGN(const string& EGN){   
    for(int i = 0; i < employees.size(); i++){
        if(EGN == employees[i].getEGN()){
            return employees[i];
        }
    }

    throw std::invalid_argument(NO_SUCH_EMPLOYEE_EGN_ERR);
}

Employee& BankDatabase::getEmployeeByUsername(const string& username){
   for(int i = 0; i < employees.size(); i++){
        if(username == employees[i].getUsername()){
            return employees[i];
        }
    }

    throw std::invalid_argument(NO_SUCH_EMPLOYEE_USER_ERR);
}

void BankDatabase::removeClient(const string& EGN){
    try{
        removeItemFromCollection(clients, EGN);
    }catch(std::invalid_argument){
        throw std::invalid_argument(NO_SUCH_CLIENT_ERR);
    }
}