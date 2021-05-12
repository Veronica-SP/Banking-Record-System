#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "Date.h"

#include "helper-functions.h"

using std::string;

class Person{
private:
    string EGN;
    string name;
    Date birthDate;
    string phoneNumber;
    string address;

    void setEGN(string EGN);
    void setName(string firstName, string secondName, string lastName);
    void setPhoneNumber(string PhoneNumber);
    void setAddress(string address);

public:
    Person(string EGN, string firstName, string secondName, string lastName,
             Date birthDate, string phoneNumber, string address);
};

#endif