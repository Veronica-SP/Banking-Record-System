#include "Client.h"

//public----------------------------

Client::Client(const string& EGN, const string& firstName, const string& middleName, const string& lastName,
            const Date& birthDate, const string& phoneNumber, const string& address)
        :Person(EGN, firstName, middleName, lastName, birthDate, phoneNumber, address), numberOfCards(0){}

string Client::generateIBAN() const{
    return BankAccount::IBAN_START + getEGN().substr(6,4) + std::to_string(getNumberOfAccounts() + 1);
}

string Client::generateCardNumber() const{
    return Card::CARD_NUM_START + getEGN().substr(6,4) + std::to_string(getNumberOfCards() + 1);
}

int Client::getNumberOfAccounts() const{
    return accounts.size();
}

int Client::getNumberOfCards() const{
    return numberOfCards;
}

BankAccount& Client::getAccountByIBAN(const string& IBAN) {
    try{
        return getItemInCollection(accounts, IBAN);
    }catch(std::logic_error){
        throw std::logic_error(NO_SUCH_ACCOUNT_IBAN_ERR);
    }
}

//find the account to which this card belongs
BankAccount& Client::getAccountByCard(const string& cardNumber){
    int cardCount = atoi(cardNumber.substr(6).c_str());

    int totalCards = 0;
    for (int i = 0; i < accounts.size(); i++)
    {   
        int currAccCards = accounts[i].getNumberOfCards();
        if(totalCards + currAccCards >= cardCount){
            return accounts[i];
        }

        totalCards += currAccCards;
    }

    throw std::logic_error(NO_SUCH_ACCOUNT_CARD_ERR);
}

Card& Client::getCard(const string& cardNumber){
    BankAccount& account = getAccountByCard(cardNumber);
    return account.getCard(cardNumber);
}

void Client::addAccount(const BankAccount& newAccount){
    accounts.push_back(newAccount);
}

void Client::removeAccount(const string& IBAN){
    try{
        removeItemFromCollection(accounts, IBAN);
    }catch(std::logic_error){
        throw std::logic_error(NO_SUCH_ACCOUNT_IBAN_ERR);
    }
}

void Client::addCard(const string& IBAN, const Card& newCard){
    BankAccount& account = getAccountByIBAN(IBAN);
    account.addCard(newCard);
    numberOfCards++;
}

void Client::removeCard(const string& IBAN, const string& cardNumber){
    BankAccount& account = getAccountByIBAN(IBAN);
    account.removeCard(cardNumber);
    numberOfCards--;
}

void Client::serialize(std::ofstream& fout) const{
    const char* separator = " ";

    Person::serialize(fout);
    fout << separator;
    serializeColl(fout, accounts, separator);
}

void Client::deserialize(std::istream& fin){
    Person::deserialize(fin);
    deserializeColl(fin, accounts);
}

std::ostream& operator<<(std::ostream& out, const Client& client){
    out << "--------Client--------" << std::endl;
    out << (Person)client << std::endl;

    int numberOfAccounts = client.getNumberOfAccounts();
    out << "Number of accounts: " << numberOfAccounts;

    if(numberOfAccounts > 0){
        out << std::endl;
    }

    out << client.accounts;

    return out;
}