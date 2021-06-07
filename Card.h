#ifndef CARD_H
#define CARD_H

#include <stdexcept>
#include <iostream>
#include <fstream>
#include "helper-functions.hpp"

class Card{
private:
    string cardNumber;
    string PIN;

    static const int MIN_CARD_NUM_LEN;
    static const char* CARD_NUM_START;
    static const int PIN_LEN;
    
    void setCardNumber(const string& cardNumber);
    void setPIN(const string& PIN);

public:
    
    Card() = default;
    Card(const string& cardNumber, const string& PIN);
    
    string getKey() const;

    string getCardNumber() const;
    void validatePIN(const string& PIN) const;

    friend std::ostream& operator<<(std::ostream& out, const Card& card);

    void serialize(std::ofstream& fout) const;
    friend std::istream& operator>>(std::istream& fin, Card& card);
};


#endif