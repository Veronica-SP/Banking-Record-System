#include "Person.h"

void Person::setEGN(string EGN){
    const int EGN_LENGTH = 10;

    if(!isOnlyDigits(EGN)){
        throw std::invalid_argument(EGN_CONTAINS_NONDIGIT_ERR);
    }

    if(EGN.length() != 10){
        throw std::invalid_argument(EGN_LENGTH_ERR);
    }

    this->EGN = EGN;

}

void Person::setName(string firstName, string secondName, string lastName){
    if(!isValidName(firstName) || !isValidName(secondName) || !isValidName(lastName)){
        throw std::invalid_argument(NAME_INVALID_ERR);
    }

    this-> name = firstName + " " + secondName + " " + lastName;
}

void Person::setPhoneNumber(string phoneNumber){
    const int PHONE_NUMBER_LENGTH = 10;

    if(!isOnlyDigits(phoneNumber)){
        throw std::invalid_argument(PHONE_CONTAINS_NONDIGIT_ERR);
    }

    if(phoneNumber.length() != 10){
        throw std::invalid_argument(PHONE_LENGTH_ERR);
    }

    this->phoneNumber = phoneNumber;
}

void Person::setAddress(string address){
    if(isEmpty(address)){
        throw std::invalid_argument(ADDRESS_EMPTY_ERR);
    }

    this->address = address;

}

Person::Person(string EGN, string firstName, string secondName, string lastName, Date birthDate, string phoneNumber, string address): birthDate(birthDate){
    setEGN(EGN);
    setName(firstName, secondName, lastName);
    setPhoneNumber(phoneNumber);
    setAddress(address);
}