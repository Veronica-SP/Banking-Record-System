#include "Employee.h"

Employee::Employee(const string& username, const string& password, 
             const string& EGN, const string& firstName, const string& secondName, const string& lastName,
             const Date& birthDate, const string& phoneNumber, const string& address)
            :DatabaseUser(username, password),
             Person(EGN, firstName, secondName, lastName, birthDate, phoneNumber, address){}

std::ostream& operator<<(std::ostream& out, const Employee& employee){
    out << "-------Employee-------" << std::endl;
    out << (DatabaseUser)employee << std::endl << (Person)employee;
    
    return out;
}

void Employee::serialize(std::ofstream& fout) const{
    const string separator = " ";

    DatabaseUser::serialize(fout);
    fout << separator;
    Person::serialize(fout);
}

std::istream& operator>>(std::istream& fin, Employee& employee){
    string separator;

    fin >> (DatabaseUser&) employee;
    fin >> (Person&) employee;
    
    return fin;
}