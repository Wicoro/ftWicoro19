#include "include/BitcoinExchange.hpp"
#include <sstream>
#include <fstream>

int main(int ac, char** av) {
    BitcoinExchange btcExchange;
    btcExchange.loadData("data.csv");

    (void) ac;
    std::ifstream file(av[1]);
    if (!file.is_open() && av[1])
        throw std::runtime_error("Could not open file: " + std::string(av[1]));
    if (!file.is_open())
        throw std::runtime_error("Could not open file: ");
    std::string line;
    std::getline(file, line); // Skip header
    while (std::getline(file, line)) {
        size_t pipePos = line.find('|');
        if (pipePos != std::string::npos) {
            try {
                btcExchange.getExchangeRate(Date(line.substr(0, pipePos)), line.substr(pipePos + 1));
            } catch (std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
        }
        else {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }
    return 0;
}