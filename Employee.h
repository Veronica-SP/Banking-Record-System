#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "DatabaseUser.h"
#include "Person.h"

class Employee : public DatabaseUser, public Person{
public:
    Employee() = default;
    Employee(const string& username, const string& password, 
             const string& EGN, const string& firstName, const string& middleName, const string& lastName,
             const Date& birthDate, const string& phoneNumber, const string& address);

    //file input/output
    void serialize(std::ofstream& fout) const;
    void deserialize(std::istream& fin);

    //console output
    friend std::ostream& operator<<(std::ostream& out, const Employee& employee);
};


#endif