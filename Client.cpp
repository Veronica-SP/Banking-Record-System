#include "Client.h"

Client::Client(const string& EGN, const string& firstName, const string& secondName, const string& lastName,
            const Date& birthDate, const string& phoneNumber, const string& address)
        :Person(EGN, firstName, secondName, lastName, birthDate, phoneNumber, address){}
    
int Client::getNumberOfAccounts() const{
    return accounts.size();
}

const BankAccount& Client::getAccount(const string& IBAN) const{
    for(int i = 0; i < accounts.size(); i++){
        if(IBAN.compare(accounts[i].getIBAN()) == 0){
            return accounts[i];
        }
    }

    throw std::invalid_argument(NO_SUCH_ACCOUNT_ERR + IBAN);
}
    
void Client::addAccount(const BankAccount& newAccount){
    accounts.push_back(newAccount);
}