#include "Date.h"

//private-------------------------------------------

void Date::setDay(const int day) {
    if(day <= 1 && day >= 31){
        throw std::invalid_argument(DAY_INVALID_ERR);
    }

    bool isFeb = (month == 2);
    bool isLeap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);

    if (isFeb){
        if (isLeap){
            if(day > 29){
                throw std::invalid_argument(LEAP_FEB_DAY_INVALID_ERR);
            }
        }else{
           if(day > 28){
                throw std::invalid_argument(FEB_DAY_INVALID_ERR);
           }
        }
    }

    bool monthHas30Days = (month == 4 || month == 6 || month == 9 || month == 11);

    if (monthHas30Days){
        if(day > 30){
                throw std::invalid_argument(DAYS30_INVALID_ERR);
           }
    }

    this->day = day;

}

void Date::setMonth(const int month) {
    if(month < 1 || month > 12){
        throw std::invalid_argument(MONTH_INVALID_ERR);
    }
    
    this->month = month;
}

void Date::setYear(const int year) {
    if(year < 0){
        throw std::invalid_argument(YEAR_INVALID_ERR);
    }

    this->year = year;
}

//public-------------------------------------------

Date::Date(const int day, const int month, const int year) {
    setYear(year);
    setMonth(month);
    setDay(day);
}

void Date::serialize(std::ofstream& fout) const{
    const char* separator = " ";
    fout << day << separator << month << separator << year;
}

void Date::deserialize(std::istream& fin){
    fin >> day >> month >> year;
}

std::ostream& operator<<(std::ostream& out, const Date& date){
    const char* separator = "/";
    out << date.day << separator << date.month << separator << date.year;

    return out;
}