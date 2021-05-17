#include "Card.h"

//private

const int Card::MIN_CARD_NUM_LEN = 7;
const int Card::PIN_LEN = 4;
const char* Card::CARD_NUM_START = "00";

void Card::setCardNumber(const string& cardNumber){
    if(cardNumber.length() < MIN_CARD_NUM_LEN){
        throw std::invalid_argument(CARD_NUM_LEN_ERR);
    }

    if(cardNumber.substr(0,2).compare(CARD_NUM_START) != 0){
        throw std::invalid_argument(CARD_NUM_START_ERR);
    }

    if(!isOnlyDigits(cardNumber)){
        throw std::invalid_argument(CARD_NUM_CONTAINS_NONDIGIT_ERR);
    }

    this->cardNumber = cardNumber;
}

void Card::setPIN(const string& PIN){
    if(PIN.length() != PIN_LEN){
        throw std::invalid_argument(PIN_LEN_ERR);
    }

    if(!isOnlyDigits(PIN)){
        throw std::invalid_argument(PIN_CONTAINS_NONDIGIT_ERR);
    }

    this->PIN  = BCrypt::generateHash(PIN);
}

Card::Card(const string& cardNumber, const string& PIN){
    setCardNumber(cardNumber);
    setPIN(PIN);
}

//public

string Card::getCardNumber() const{
    return cardNumber;
}

void Card::validatePIN(const string& PIN) const{
    bool PINIsValid = BCrypt::validatePassword(PIN, this->PIN);

    if(!PINIsValid){
        throw std::logic_error(PIN_WRONG_ERR);
    }
}