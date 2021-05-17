#ifndef CLIENT_H
#define CLIENT_H

#include "Person.h"
#include "BankAccount.h"
#include <vector>

using std::vector;

class Client : public Person{
private:
    vector<BankAccount> accounts;

public:
    Client(const string& EGN, const string& firstName, const string& secondName, const string& lastName,
            const Date& birthDate, const string& phoneNumber, const string& address);
    
    int getNumberOfAccounts() const;
    const BankAccount& getAccount(const string& IBAN) const;
    
    void addAccount(const BankAccount& newAccount);
};


#endif