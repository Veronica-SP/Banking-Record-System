#ifndef DATE_H
#define DATE_H

#include <stdexcept>
#include <iostream>
#include <fstream>

#include "messages.h"

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

    //file input/output
    void serialize(std::ofstream& fout) const;
    void deserialize(std::istream& fin);

    //console output
    friend std::ostream& operator<<(std::ostream& out, const Date& date);
};

#endif 
