#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "DatabaseUser.h"
#include "Person.h"

class Employee : public DatabaseUser, public Person{

};


#endif