#ifndef PERSON_H
#define PERSON_H

#include "Date.h"
#include "helper-functions.hpp"

class Person{
private:
    string EGN;
    string firstName;
    string middleName;
    string lastName;
    Date birthDate;
    string phoneNumber;
    string address;

    //static fields
    static const int EGN_LEN;
    static const int PHONE_NUMBER_LEN;

protected:
    void setEGN(const string& EGN);
    void setName(const string& firstName, const string& middleName, const string& lastName);
    void setPhoneNumber(const string& phoneNumber);
    void setAddress(const string& address);

    Person() = default;
    Person(const string& EGN, const string& firstName, const string& middleName, const string& lastName,
             const Date& birthDate, const string& phoneNumber, const string& address);

public:

    string getEGN() const;
    string getKey() const;

    //file input/output
    void serialize(std::ofstream& fout) const;
    void deserialize(std::istream& fin);

    //console output
    friend std::ostream& operator<<(std::ostream& out, const Person& person);

};

#endif