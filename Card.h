#ifndef CARD_H
#define CARD_H

#include <string>
#include <stdexcept>
#include "Dependencies/libbcrypt/include/bcrypt/BCrypt.hpp"

#include "messages.h"
#include "helper-functions.h"

using std::string;

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
    Card(const string& cardNumber, const string& PIN);

    string getCardNumber() const;
    void validatePIN(const string& PIN) const;
};


#endif