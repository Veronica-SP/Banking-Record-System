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

    this->PIN  = PIN;
}

Card::Card(const string& cardNumber, const string& PIN){
    setCardNumber(cardNumber);
    setPIN(PIN);
}

//public

string Card::getKey() const{
    return cardNumber;
}

string Card::getCardNumber() const{
    return cardNumber;
}


void Card::validatePIN(const string& PIN) const{
    bool PINIsValid = PIN.compare(this->PIN);

    if(!PINIsValid){
        throw std::logic_error(PIN_WRONG_ERR);
    }
}

std::ostream& operator<<(std::ostream& out, const Card& card){
    out << "----Card-----" << std::endl;
    out << "Card number: " << card.cardNumber << std::endl;
    out << "PIN: " << card.PIN;

    return out;
}

void Card::serialize(std::ofstream& fout) const{
    const string separator = " ";
    fout << cardNumber << separator << PIN;
}

std::istream& operator>>(std::istream& fin, Card& card){

    fin >> card.cardNumber >> card.PIN;

    return fin;
}