#include "Employee.h"

//public-----------------------------

Employee::Employee(const string& username, const string& password, 
             const string& EGN, const string& firstName, const string& middleName, const string& lastName,
             const Date& birthDate, const string& phoneNumber, const string& address)
            :DatabaseUser(username, password),
             Person(EGN, firstName, middleName, lastName, birthDate, phoneNumber, address){}

void Employee::serialize(std::ofstream& fout) const{
    const char* separator = " ";

    DatabaseUser::serialize(fout);
    fout << separator;
    Person::serialize(fout);
}

void Employee::deserialize(std::istream& fin){
    DatabaseUser::deserialize(fin);
    Person::deserialize(fin);
}

std::ostream& operator<<(std::ostream& out, const Employee& employee){
    out << "-------Employee-------" << std::endl;
    out << (DatabaseUser)employee << std::endl << (Person)employee;
    
    return out;
}