#ifndef CLIENT_H
#define CLIENT_H

#include "Person.h"
#include "BankAccount.h"

class Client : public Person{
private:
    vector<BankAccount> accounts;

public:
    Client() = default;
    Client(const string& EGN, const string& firstName, const string& secondName, const string& lastName,
             const Date& birthDate, const string& phoneNumber, const string& address);
    
    int getNumberOfAccounts() const;
    BankAccount& getAccount(const string& IBAN);

    void addAccount(const BankAccount& newAccount);
    void removeAccount(const string& IBAN);

    friend std::ostream& operator<<(std::ostream& out, const Client& client);

    void serialize(std::ofstream& fout) const;
    friend std::istream& operator>>(std::istream& fin, Client& client);
};


#endif