#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
    std::ifstream data;
    data.open("data.csv");
    if (!data.is_open()){
		throw std::ios_base::failure(std::string("BitcoinExchange: ") + "data.csv");
    }
    std::string buffer, key, value;
    while (std::getline(data, buffer)){
        if (buffer == "date,exchange_rate")
            continue;
        std::istringstream iss(buffer);
        std::getline(iss, key, ',');
        std::getline(iss, value, ',');
        this->_priceHistory[key] = std::atof(value.c_str());
    }
    data.close();
}

// BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs){}

// BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs){}

BitcoinExchange::~BitcoinExchange(){}

// void    checkValue(){}

