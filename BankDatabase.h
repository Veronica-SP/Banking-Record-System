#ifndef DATABASE_H
#define DATABASE_H

#include "Admin.h"
#include "Employee.h"
#include "Client.h"

class BankDatabase{
private:
    Admin* admin;
    vector<Employee> employees;
    vector<Client> clients;

    static const char* ADMIN_FILENAME;
    static const char* EMPLOYEES_FILENAME;
    static const char* CLIENTS_FILENAME;

    void loadDatabase();
    void serializeDatabase();
    void copyDatabase(const BankDatabase& other);

public:
    BankDatabase();
    BankDatabase(const BankDatabase& other);
    BankDatabase& operator=(const BankDatabase& other);
    ~BankDatabase();

    bool hasAdmin() const;
    void setAdmin(const Admin& admin);

    void addEmployee(const Employee& newEmployee);
    Employee& getEmployeeByEGN(const string& EGN);
    Employee& getEmployeeByUsername(const string& username);
    void removeEmployee(const string& EGN);

    void addClient(const Client& newClient);
    Client& getClient(const string& EGN);
    void removeClient(const string& EGN);
};

#endif