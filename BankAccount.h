#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include "Card.h"

class BankAccount{
private:
    string IBAN;
    double balance;
    vector<Card> cards;

    //static fields
    static const char* IBAN_START;
    static const int MIN_IBAN_LEN;

    void setIBAN(const string& IBAN);
    void setBalance(const double balance);

    friend class Client;

public:
    BankAccount() = default;
    BankAccount(const string& IBAN, const double balance = 0.0);

    string getIBAN() const;
    string getKey() const;
    double getBalance() const;
    int getNumberOfCards() const;
    Card& getCard(const int index);
    Card& getCard(const string& cardNumber);

    //employee actions
    void addCard(const Card& newCard);
    void removeCard(const string& cardNumber);

    //client actions
    void deposit(const double amount);
    void withdraw(const double amount);

    //file input/output
    void serialize(std::ofstream& fout) const;
    void deserialize(std::istream& fin);

    //console output
    friend std::ostream& operator<<(std::ostream& out, const BankAccount& account);
};


#endif