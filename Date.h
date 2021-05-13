#ifndef DATE_H
#define DATE_H

#include <stdexcept>
#include "messages.h"

class Date{
private:
    int day;
    int month;
    int year;

    void setDay(const int day);
    void setMonth(const int month);
    void setYear(const int year);

    //void inputNumber(std::ifstream& fin, int& number, const int length);
    //oid DateTime::serialize(std::ostream& fout) const;
public:
    Date(const int day, const int month, const int year);
    
    int getDay() const;
    int getMonth() const;
    int getYear() const;
   // void writeToFile(std::ofstream&) const;
    //void readFromFile(std::ifstream&);
    //void printTimestamp() const;
};

#endif 
