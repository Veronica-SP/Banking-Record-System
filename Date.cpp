#include "Date.h"

//private

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
        throw std::invalid_argument(MONTH_IVALID_ERR);
    }
    
    this->month = month;

}

void Date::setYear(const int year) {
    if(year < 0){
        throw std::invalid_argument(YEAR_INVALID_ERR);
    }

    this->year = year;

}

//public

Date::Date(const int day, const int month, const int year) {
    setYear(year);
    setMonth(month);
    setDay(day);
}

int Date::getDay() const{
    return day;
}

int Date::getMonth() const{
    return month;
}

int Date::getYear() const{
    return year;
}

std::ostream& operator<<(std::ostream& out, const Date& date){
    const string separator = "/";

    out << date.day << separator << date.month << separator << date.year;

    return out;
}

void Date::serialize(std::ofstream& fout) const{
    const string separator = " ";

    fout << day << separator << month << separator << year;
}

std::istream& operator>>(std::istream& fin, Date& date){

    fin >> date.day >> date.month >> date.year;

    return fin;
}