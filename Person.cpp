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

    this->firstName = firstName;
    this->secondName = secondName;
    this->lastName = lastName;
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

    if(address[0] != '\"' || address[address.length() - 1] != '\"'){
        throw std::invalid_argument(ADDRESS_PARANTH_ERR);
    }
    this->address = address;

}

Person::Person(const string& EGN, const string& firstName, const string& secondName, const string& lastName,
                 const Date& birthDate, const string& phoneNumber, const string& address): birthDate(birthDate){
    setEGN(EGN);
    setName(firstName, secondName, lastName);
    setPhoneNumber(phoneNumber);
    setAddress(address);
}

//public:

string Person::getKey() const{
    return EGN;
}

string Person::getEGN() const{
    return EGN;
}

string Person::getName() const{
    return firstName + " " + secondName + " " + lastName;
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

std::ostream& operator<<(std::ostream& out, const Person& person){
    out << "EGN: " << person.EGN << std::endl;
    out << "Name: " << person.getName() << std::endl;
    out << "Birth date: " << person.birthDate << std::endl;
    out << "Phone number: " << person.phoneNumber << std::endl;
    out << "Address: " << person.address;

    return out;
}
void Person::serialize(std::ofstream& fout) const{
    const string separator = " ";

    fout << EGN << separator << getName() << separator;
    birthDate.serialize(fout);
    fout << separator << phoneNumber << separator << address;
}

std::istream& operator>>(std::istream& fin, Person& person){

    fin >> person.EGN >> person.firstName >> person.secondName >> person.lastName
        >> person.birthDate >> person.phoneNumber;

    while(fin.peek() != '\"'){
        fin.get();
    }
    
    person.address += fin.get();

    string addressTemp;
    getline(fin, addressTemp, '\"');
    fin.get();
    
    person.address += addressTemp;
    person.address += "\"";

    return fin;
}