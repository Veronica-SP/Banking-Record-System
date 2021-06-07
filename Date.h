#ifndef DATE_H
#define DATE_H

#include <stdexcept>
#include "messages.h"
#include <iostream>
#include <fstream>
#include <string>

using std::string;

class Date{
private:
    int day;
    int month;
    int year;

    void setDay(const int day);
    void setMonth(const int month);
    void setYear(const int year);

public:
    Date() = default;
    Date(const int day, const int month, const int year);
    
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    
    friend std::ostream& operator<<(std::ostream& out, const Date& date);

    void serialize(std::ofstream& out) const;
    friend std::istream& operator>>(std::istream& fin, Date& date);
};

#endif 
