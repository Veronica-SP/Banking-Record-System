#ifndef CARD_H
#define CARD_H

#include <stdexcept>
#include <stdlib.h>

#include "helper-functions.hpp"

class Card{
private:
    string cardNumber;
    string PIN;

    //static fields
    static const char* CARD_NUM_START;
    static const int MIN_CARD_NUM_LEN;
    static const int PIN_LEN;

    void setCardNumber(const string& cardNumber);
    void setPIN(const string& PIN);

    friend class Client;
    friend class BankDatabase;

public:
    Card() = default;
    Card(const string& cardNumber, const string& PIN);
    
    string getCardNumber() const;
    string getKey() const;
    bool validatePIN(const string& PIN) const;

    //file input/output
    void serialize(std::ofstream& fout) const;
    void deserialize(std::istream& fin);

    //console output
    friend std::ostream& operator<<(std::ostream& out, const Card& card);

    //static methods
    static string generateRandPIN();
};


#endif