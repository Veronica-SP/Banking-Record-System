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
/*void DateTime::serialize(std::ostream& fout) const {
    fout << std::setw(2) << std::setfill('0') << day << " ";
    fout << months[month - 1] << " ";
    fout << std::setw(4) << std::setfill('0') << year << ", ";
    fout << std::setw(2) << std::setfill('0') << hours << ":";
    fout << std::setw(2) << std::setfill('0') << minutes << ":";
    fout << std::setw(2) << std::setfill('0') << seconds;
}*/

/*void DateTime::inputNumber(std::ifstream& fin, int& number, const int length){
    char numberArr[length];

    fin.read(numberArr, length);
    number = atoi(numberArr);

    do{
        fin.get();
    }while(fin.peek() == ' ' || fin.peek() == ',' || fin.peek() == ':');
}*/

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

/*
void Date::writeToFile(std::ofstream& fout) const {
    serialize(fout);
}

void Date::readFromFile(std::ifstream& fin) {
    
    inputNumber(fin, day, 2);

    char  monthInText[4];
    fin.get(monthInText, 4);
    month = getMonthNumber(monthInText);
    fin.get();

    inputNumber(fin, year, 4);
    inputNumber(fin, hours, 2);
    inputNumber(fin, minutes, 2);
    inputNumber(fin, seconds, 2);
}

void Date::printTimestamp() const {
    serialize(std::cout);
}
*/