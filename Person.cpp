#include "Person.h"

//private---------------------------------------------

const int Person::EGN_LEN = 10;
const int Person::PHONE_NUMBER_LEN = 10;

//protected-------------------------------------------

void Person::setEGN(const string& EGN){
    if(!isOnlyDigits(EGN)){
        throw std::invalid_argument(EGN_CONTAINS_NONDIGIT_ERR);
    }

    if(EGN.length() != EGN_LEN){
        throw std::invalid_argument(EGN_LENGTH_ERR);
    }

    this->EGN = EGN;

}

void Person::setName(const string& firstName, const string& middleName, const string& lastName){
    if(!isValidName(firstName) || !isValidName(middleName) || !isValidName(lastName)){
        throw std::invalid_argument(NAME_INVALID_ERR);
    }

    this->firstName = firstName;
    this->middleName = middleName;
    this->lastName = lastName;
}

void Person::setPhoneNumber(const string& phoneNumber){

    if(!isOnlyDigits(phoneNumber)){
        throw std::invalid_argument(PHONE_CONTAINS_NONDIGIT_ERR);
    }

    if(phoneNumber.length() != EGN_LEN){
        throw std::invalid_argument(PHONE_LENGTH_ERR);
    }

    this->phoneNumber = phoneNumber;
}

void Person::setAddress(const string& address){
    if(isEmpty(address)){
        throw std::invalid_argument(ADDRESS_EMPTY_ERR);
    }

    if(address[0] != '\"' || address[address.length() - 1] != '\"'){
        throw std::invalid_argument(ADDRESS_PARANTH_ERR);
    }
    this->address = address;

}

Person::Person(const string& EGN, const string& firstName, const string& middleName, const string& lastName,
                 const Date& birthDate, const string& phoneNumber, const string& address): birthDate(birthDate){
    setEGN(EGN);
    setName(firstName, middleName, lastName);
    setPhoneNumber(phoneNumber);
    setAddress(address);
}

//public-------------------------------------------

string Person::getEGN() const{
    return EGN;
}

string Person::getKey() const{
    return EGN;
}

void Person::serialize(std::ofstream& fout) const{
    const char* separator = " ";

    fout << EGN << separator << firstName << separator << middleName << separator << lastName << separator;
    birthDate.serialize(fout);
    fout << separator << phoneNumber << separator << address;
}

void Person::deserialize(std::istream& fin){
    fin >> EGN >> firstName >> middleName >> lastName;
    birthDate.deserialize(fin);
    fin >> phoneNumber;

    while(fin.get() != '\"'){
    }

    getline(fin, address, '\"');
    fin.get();
    
    address.insert(0, "\"");
    address += "\"";
}

std::ostream& operator<<(std::ostream& out, const Person& person){
    out << "EGN: " << person.EGN << std::endl;
    out << "Name: " << person.firstName << " " << person.middleName << " " << person.lastName << std::endl;
    out << "Birth date: " << person.birthDate << std::endl;
    out << "Phone number: " << person.phoneNumber << std::endl;
    out << "Address: " << person.address;

    return out;
}