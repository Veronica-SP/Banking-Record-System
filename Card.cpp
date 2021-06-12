#include "Card.h"

//private-------------------------------------------

const char* Card::CARD_NUM_START = "00";
const int Card::MIN_CARD_NUM_LEN = 7;
const int Card::PIN_LEN = 4;

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

//public-------------------------------------------

Card::Card(const string& cardNumber, const string& PIN){
    setCardNumber(cardNumber);
    setPIN(PIN);
}

string Card::getCardNumber() const{
    return cardNumber;
}

string Card::getKey() const{
    return cardNumber;
}

bool Card::validatePIN(const string& PIN) const{
    return this->PIN == PIN;
}

void Card::serialize(std::ofstream& fout) const{
    const char* separator = " ";
    fout << cardNumber << separator << PIN;
}

void Card::deserialize(std::istream& fin){
    fin >> cardNumber >> PIN;
}

std::ostream& operator<<(std::ostream& out, const Card& card){
    out << "-----Card-----" << std::endl;
    out << "Card number: " << card.cardNumber << std::endl;
    out << "PIN: " << card.PIN;

    return out;
}

string Card::generateRandPIN(){

    int n1 = rand() % 10;
    int n2 = rand() % 10;
    int n3 = rand() % 10;
    int n4 = rand() % 10;

    return std::to_string(n1) + std::to_string(n2) + std::to_string(n3) + std::to_string(n4);
}