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

protected:
    void setEGN(const string& EGN);
    void setName(const string& firstName, const string& secondName, const string& lastName);
    void setPhoneNumber(const string& PhoneNumber);
    void setAddress(const string& address);

public:
    Person(const string& EGN, const string& firstName, const string& secondName, const string& lastName,
             const Date& birthDate, const string& phoneNumber, const string& address);
    virtual ~Person() = default;

    string getEGN() const;
    string getName() const;
    const Date& getBirthDate() const;
    string getPhoneNumber() const;
    string getAddress() const;

};

#endif