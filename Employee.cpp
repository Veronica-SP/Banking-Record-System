#include "Employee.h"

Employee::Employee(const string& username, const string& password, 
             const string& EGN, const string& firstName, const string& secondName, const string& lastName,
             const Date& birthDate, const string& phoneNumber, const string& address)
            :DatabaseUser(username, password),
             Person(EGN, firstName, secondName, lastName, birthDate, phoneNumber, address){}