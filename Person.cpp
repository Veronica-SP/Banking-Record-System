#include "Person.h"

//protected:

void Person::setEGN(const string& EGN){
    const int EGN_LENGTH = 10;

    if(!isOnlyDigits(EGN)){
        throw std::invalid_argument(EGN_CONTAINS_NONDIGIT_ERR);
    }

    if(EGN.length() != 10){
        throw std::invalid_argument(EGN_LENGTH_ERR);
    }

    this->EGN = EGN;

}

void Person::setName(const string& firstName, const string& secondName, const string& lastName){
    if(!isValidName(firstName) || !isValidName(secondName) || !isValidName(lastName)){
        throw std::invalid_argument(NAME_INVALID_ERR);
    }

    this-> name = firstName + " " + secondName + " " + lastName;
}

void Person::setPhoneNumber(const string& phoneNumber){
    const int PHONE_NUMBER_LENGTH = 10;

    if(!isOnlyDigits(phoneNumber)){
        throw std::invalid_argument(PHONE_CONTAINS_NONDIGIT_ERR);
    }

    if(phoneNumber.length() != 10){
        throw std::invalid_argument(PHONE_LENGTH_ERR);
    }

    this->phoneNumber = phoneNumber;
}

void Person::setAddress(const string& address){
    if(isEmpty(address)){
        throw std::invalid_argument(ADDRESS_EMPTY_ERR);
    }

    this->address = address;

}

//public:

Person::Person(const string& EGN, const string& firstName, const string& secondName, const string& lastName,
                 const Date& birthDate, const string& phoneNumber, const string& address): birthDate(birthDate){
    setEGN(EGN);
    setName(firstName, secondName, lastName);
    setPhoneNumber(phoneNumber);
    setAddress(address);
}

string Person::getEGN() const{
    return EGN;
}

string Person::getName() const{
    return name;
}

const Date& Person::getBirthDate() const{
    return birthDate;
}

string Person::getPhoneNumber() const{
    return phoneNumber;
}

string Person::getAddress() const{
    return address;
}