#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include "Card.h"

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
    
    BankAccount() = default;
    BankAccount(const string& IBAN, const double balance = 0.0);

    string getKey() const;

    string getIBAN() const;
    double getBalance() const;
    int getNumberOfCards() const;
    Card& getCard(const string& cardNumber);

    void addCard(const Card& newCard);
    void removeCard(const string& cardNumber);

    void deposit(const int amount);
    void withdraw(const int amount);

    friend std::ostream& operator<<(std::ostream& out, const BankAccount& account);

    void serialize(std::ofstream& fout) const;
    friend std::istream& operator>>(std::istream& fin, BankAccount& card);
};


#endif