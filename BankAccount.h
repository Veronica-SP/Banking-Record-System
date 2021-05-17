#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>
#include <vector>
#include "Card.h"

#include "messages.h"

using std::string;
using std::vector;

class BankAccount{
private:
    string IBAN;
    double balance;
    vector<Card> cards;

    static const int MIN_IBAN_LEN;
    static const char* IBAN_START;

    void setIBAN(const string& IBAN);
    void setBalance(const double balance);

public:
    BankAccount(const string& IBAN, const double balance = 0.0);
    
    string getIBAN() const;
    double getBalance() const;
    int getNumberOfCards() const;
    const Card& getCard(const string& cardNumber);

    void addCard(const Card& newCard);
    void deposit(const int amount);
    void withdraw(const int amount);
    
};


#endif