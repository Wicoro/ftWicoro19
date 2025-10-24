#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>
#include <string>
#include <exception>
#include <map>

class Date {
private:
    int year;
    int month;
    int day;
public:
    //Canonical form
    Date(std::string date);
    Date(const Date& other);
    Date& operator=(const Date& other);
    ~Date();

    bool operator<(const Date &other) const;
    bool operator>(const Date &other) const;

    //Methods
    Date getClosestDate(const Date d, std::map<Date, float> data) const;
    int getYear() const;
    int getMonth() const;
    int getDay() const;
};

std::ostream& operator<<(std::ostream& os, const Date& d);


#endif