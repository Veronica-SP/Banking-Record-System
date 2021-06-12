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

    //static fields
    static const char* ADMIN_FILENAME;
    static const char* EMPLOYEES_FILENAME;
    static const char* CLIENTS_FILENAME;

    void copyDatabase(const BankDatabase& other);

public:
    BankDatabase();
    BankDatabase(const BankDatabase& other);
    BankDatabase& operator=(const BankDatabase& other);
    ~BankDatabase();

    bool hasAdmin() const;
    void setAdmin(const Admin& admin);
    Admin& getAdmin();

    Employee& getEmployeeByEGN(const string& EGN);
    Employee& getEmployeeByUsername(const string& username);

    Client& getClientByEGN(const string& EGN);
    Client& getClientByCard(const string& cardNumber);

    //admin actions
    void addEmployee(const Employee& newEmployee);
    void removeEmployee(const string& EGN);

    //employee actions
    void addClient(const Client& newClient);
    void removeClient(const string& EGN);
    void printClientsReport() const;
    void printIndividualReport(const string& EGN);

    //file input/output
    void serializeDatabase() const;
    void deserializeDatabase();
};

#endif