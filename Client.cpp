#include "Client.h"

Client::Client(const string& EGN, const string& firstName, const string& secondName, const string& lastName,
            const Date& birthDate, const string& phoneNumber, const string& address)
        :Person(EGN, firstName, secondName, lastName, birthDate, phoneNumber, address){}
    
int Client::getNumberOfAccounts() const{
    return accounts.size();
}

BankAccount& Client::getAccount(const string& IBAN) {
    try{
        return getItemInCollection(accounts, IBAN);
    }catch(std::invalid_argument){
        throw std::invalid_argument(NO_SUCH_ACCOUNT_ERR);
    }
}

void Client::addAccount(const BankAccount& newAccount){
    accounts.push_back(newAccount);
}

void Client::removeAccount(const string& IBAN){
    try{
        removeItemFromCollection(accounts, IBAN);
    }catch(std::invalid_argument){
        throw std::invalid_argument(NO_SUCH_ACCOUNT_ERR);
    }

}

std::ostream& operator<<(std::ostream& out, const Client& client){
    out << "-------Client-------" << std::endl;
    out << (Person)client << std::endl;

    int numberOfAccounts = client.getNumberOfAccounts();
    out << "Number of accounts: " << numberOfAccounts << std::endl;

    for(int i = 0; i < numberOfAccounts; i++){
        out << client.accounts[i] << std::endl;
    }

    return out;
}

void Client::serialize(std::ofstream& fout) const{
    const string separator = " ";

    Person::serialize(fout);
    fout << separator;
    ::serialize(fout, accounts, separator);
}

std::istream& operator>>(std::istream& fin, Client& client){
    
    fin >> (Person&) client;
    fin >> client.accounts;

    return fin;
}