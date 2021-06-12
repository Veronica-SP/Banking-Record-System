#include "BankAccount.h"

//private-------------------------------------------

const char* BankAccount::IBAN_START = "00MYBANK";
const int BankAccount::MIN_IBAN_LEN = 13;

void BankAccount::setIBAN(const string& IBAN){
    if(IBAN.length() < MIN_IBAN_LEN){
        throw std::invalid_argument(IBAN_LEN_ERR);
    }

    if(IBAN.substr(0,8).compare(IBAN_START) != 0){
        throw std::invalid_argument(IBAN_START_ERR);
    }

    if(!isOnlyDigits(IBAN.substr(8))){
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

//public-------------------------------------------

BankAccount::BankAccount(const string& IBAN, const double balance){
    setIBAN(IBAN);
    setBalance(balance);
}
  
string BankAccount::getIBAN() const{
    return IBAN;
}

string BankAccount::getKey() const{
    return IBAN;
}

double BankAccount::getBalance() const{
    return balance;
}

int BankAccount::getNumberOfCards() const{
    return cards.size();
}

Card& BankAccount::getCard(const int index){
    return cards[index];
}

Card& BankAccount::getCard(const string& cardNumber){
    try{
        return getItemInCollection(cards, cardNumber);
    }catch(std::logic_error){
        throw std::logic_error(NO_SUCH_CARD_ERR);
    }

}

void BankAccount::addCard(const Card& newCard){
    cards.push_back(newCard);
}

void BankAccount::removeCard(const string& cardNumber){
    try{
        return removeItemFromCollection(cards, cardNumber);
    }catch(std::logic_error){
        throw std::logic_error(NO_SUCH_CARD_ERR);
    }
}

void BankAccount::deposit(const double amount){
    if(amount <= 0){
        throw std::invalid_argument(NEGATIVE_AMOUNT_DEPOSIT_ERR);
    }
    setBalance(balance + amount);
}

void BankAccount::withdraw(const double amount){
    if(amount <= 0){
        throw std::invalid_argument(NEGATIVE_AMOUNT_WITHDRAW_ERR);
    }

    try{
        setBalance(balance - amount);
    }catch(std::invalid_argument){
        throw std::logic_error(NOT_ENOUGH_WITHDRAW_ERR);
    }
}

void BankAccount::serialize(std::ofstream& fout) const{
    const char* separator = " ";
    fout << IBAN << separator << balance << separator;
    serializeColl(fout, cards, separator);
}

void BankAccount::deserialize(std::istream& fin){
    fin >> IBAN >> balance;
    deserializeColl(fin, cards);
}

std::ostream& operator<<(std::ostream& out, const BankAccount& account){
    out << "------Account------" << std::endl;
    out << "Acc number: " << account.IBAN << std::endl;
    out << "Balance: " << account.balance << std::endl;

    int numberOfCards = account.getNumberOfCards();
    out << "Number of cards: " << numberOfCards;

    if(numberOfCards > 0){
        out << std::endl;
    }

    out << account.cards;

    return out;
}