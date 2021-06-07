#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "DatabaseUser.h"
#include "Person.h"

class Employee : public DatabaseUser, public Person{
public:

    Employee() = default;
    Employee(const string& username, const string& password, 
             const string& EGN, const string& firstName, const string& secondName, const string& lastName,
             const Date& birthDate, const string& phoneNumber, const string& address);

    friend std::ostream& operator<<(std::ostream& out, const Employee& employee);

    void serialize(std::ofstream& fout) const;
    friend std::istream& operator>>(std::istream& fin, Employee& employee);
};


#endif