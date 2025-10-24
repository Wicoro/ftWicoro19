#include "include/Date.hpp"
#include <sstream>

//Canonical form

static int atoi(const std::string& str) {
    std::istringstream iss(str);
    int value = 0;
    iss >> value;
    return (value);
}

Date::Date(std::string date) {
    year = 0;
    size_t first_dash = date.find('-');
    size_t second_dash = date.find('-', first_dash + 1);
    size_t third_dash = date.find('-', second_dash + 1);

    if (first_dash == std::string::npos || second_dash == std::string::npos || third_dash != std::string::npos) {
        std::cerr << "Error: bad date format : " << date << std::endl;
        return ;
    }
    year =  atoi(date.substr(0, first_dash));
    month = atoi(date.substr(first_dash + 1, second_dash - first_dash - 1));
    day = atoi(date.substr(second_dash + 1));
}

Date::Date(const Date& other) : year(other.year), month(other.month), day(other.day) {}

Date& Date::operator=(const Date& other) {
    if (this != &other) {
        year = other.year;
        month = other.month;
        day = other.day;
    }
    return *this;
}

Date::~Date() {}

//Compare
bool Date::operator<(const Date &other) const {
    if (year != other.year)
        return (year < other.year);
    if (month != other.month)
        return (month < other.month);
    return (day < other.day);
}

bool Date::operator>(const Date &other) const {
    if (year != other.year)
        return (year > other.year);
    if (month != other.month)
        return (month > other.month);
    return (day > other.day);
}

//Methods
Date Date::getClosestDate(const Date d, std::map<Date, float> data) const {
    if (data.find(d) != data.end())
        return (d);
    std::map<Date, float>::iterator it = data.lower_bound(d);
    if (it == data.begin())
        return (it->first);
    --it;
    return (it->first);
}

int Date::getYear() const {
    return year;
}

int Date::getMonth() const {
    return month;
}
int Date::getDay() const {
    return day;
}

std::ostream& operator<<(std::ostream& os, const Date& d) {
	os << d.getYear() << "-" << d.getMonth() << "-" << d.getDay();
	return os;
}