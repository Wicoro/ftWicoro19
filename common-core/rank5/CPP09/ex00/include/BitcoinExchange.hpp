#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <string>
#include <exception>
#include <map>

#include "Date.hpp"

class BitcoinExchange
{
private:
    std::map<Date, float> data;
public:
    //Canonical form
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    //Methods
    void loadData(const std::string& filename);
    void getExchangeRate(const Date d, std::string s) const;
};

#endif