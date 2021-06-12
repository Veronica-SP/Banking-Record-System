#ifndef CLIENT_H
#define CLIENT_H

#include "Person.h"
#include "BankAccount.h"

class Client : public Person{
private:
    vector<BankAccount> accounts;
    int numberOfCards;

public:
    Client() = default;
    Client(const string& EGN, const string& firstName, const string& middleName, const string& lastName,
             const Date& birthDate, const string& phoneNumber, const string& address);
    
    string generateIBAN() const;
    string generateCardNumber() const;

    int getNumberOfAccounts() const;
    int getNumberOfCards() const;
    BankAccount& getAccountByIBAN(const string& IBAN);
    //find account from login info
    BankAccount& getAccountByCard(const string& cardNumber);
    Card& getCard(const string& cardNumber);

    //employee actions
    void addAccount(const BankAccount& newAccount);
    void removeAccount(const string& IBAN);
    void addCard(const string& IBAN, const Card& newCard);
    void removeCard(const string& IBAN, const string& cardNumber);

    //file input/output
    void serialize(std::ofstream& fout) const;
    void deserialize(std::istream& fin);

    //console output
    friend std::ostream& operator<<(std::ostream& out, const Client& client);
};


#endif