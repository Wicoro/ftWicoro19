#include "include/BitcoinExchange.hpp"
#include <sstream>
#include <fstream>

//Canonical form
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : data(other.data) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        data = other.data;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

//Methods

static float atof(const std::string& str) {
    std::istringstream iss(str);
    float value = 0;
    iss >> value;
    return (value);
}

void BitcoinExchange::loadData(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }

    std::string line;
    std::getline(file, line); // Skip header
    while (std::getline(file, line)) {
        size_t commaPos = line.find(',');
        if (commaPos != std::string::npos) {
            std::string dateStr = line.substr(0, commaPos);
            std::string rateStr = line.substr(commaPos + 1);
            Date date(dateStr);
            float rate = atof(rateStr);
            data[date] = rate;
        }
    }
    file.close();
}

void BitcoinExchange::getExchangeRate(const Date d, const std::string s) const {
    float f = atof(s);

    if (f < 0) {
        std::cerr << "Error: not a positive number." << std::endl;
        return ;
    } else if (f > 1000) {
        std::cerr << "Error: too large a number." << std::endl;
        return ;
    }
    if (d.getYear() == 0) {
        return ;
    }
    Date closestDate = d.getClosestDate(d, data);
    float value = data.at(closestDate) * f;
    std::cout << d << " => " << f << " = " << value << std::endl;
}
