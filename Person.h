#ifndef PERSON_H
#define PERSON_H

#include "Date.h"
#include "helper-functions.hpp"

class Person{
private:
    string EGN;
    string firstName;
    string secondName;
    string lastName;
    Date birthDate;
    string phoneNumber;
    string address;

protected:
    void setEGN(const string& EGN);
    void setName(const string& firstName, const string& secondName, const string& lastName);
    void setPhoneNumber(const string& PhoneNumber);
    void setAddress(const string& address);

    Person() = default;
    Person(const string& EGN, const string& firstName, const string& secondName, const string& lastName,
             const Date& birthDate, const string& phoneNumber, const string& address);

public:

    string getKey() const;

    string getEGN() const;
    string getName() const;
    const Date& getBirthDate() const;
    string getPhoneNumber() const;
    string getAddress() const;


    friend std::ostream& operator<<(std::ostream& out, const Person& person);

    void serialize(std::ofstream& fout) const;
    friend std::istream& operator>>(std::istream& fin, Person& person);

};

#endif