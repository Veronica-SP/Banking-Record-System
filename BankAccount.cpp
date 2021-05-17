#include "BankAccount.h"

//private

const int BankAccount::MIN_IBAN_LEN = 13;
const char* BankAccount::IBAN_START = "00MYBANK";

void BankAccount::setIBAN(const string& IBAN){
    if(IBAN.length() < MIN_IBAN_LEN){
        throw std::invalid_argument(IBAN_LEN_ERR);
    }

    if(IBAN.substr(0,8).compare(IBAN_START) != 0){
        throw std::invalid_argument(IBAN_START_ERR);
    }

    if(!isOnlyDigits(IBAN.substr(0,8))){
        throw std::invalid_argument(IBAN_CONTAINS_NONDIGIT_ERR);
    }

    this->IBAN = IBAN;
}

void BankAccount::setBalance(const double balance){
    if(balance < 0){
        throw std::invalid_argument(NEGATIVE_BALANCE_ERR);
    }

    this->balance = balance;
}

//public

BankAccount::BankAccount(const string& IBAN, const double balance = 0.0){
    setIBAN(IBAN);
    setBalance(balance);
}
    
string BankAccount::getIBAN() const{
    return IBAN;
}

double BankAccount::getBalance() const{
    return balance;
}

int BankAccount::getNumberOfCards() const{
    return cards.size();
}

const Card& BankAccount::getCard(const string& cardNumber){
    for(int i = 0; i < cards.size(); i++){
        if(cardNumber.compare(cards[i].getCardNumber()) == 0){
            return cards[i];
        }
    }

    throw std::invalid_argument(NO_SUCH_CARD_ERR + cardNumber);
}

void BankAccount::addCard(const Card& newCard){
    cards.push_back(newCard);
}

void BankAccount::deposit(const int amount){
    setBalance(balance + amount);
}

void BankAccount::withdraw(const int amount){
    setBalance(balance - amount);
}