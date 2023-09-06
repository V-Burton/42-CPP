#pragma once

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>
#include <stdlib.h>
#include <sstream>

#define END				"\033[0m"
#define BOLD			"\033[1m"
#define UNDERLINE		"\033[4m"
#define BLUE			"\033[34m"
#define YELLOW			"\033[33m"
#define CYAN			"\033[36m"
#define GREEN			"\033[32m"
#define RED				"\033[31m"

class BitcoinExchange{
    public:
        BitcoinExchange();
        ~BitcoinExchange();

        void    ConvertStringToFloat();


    private:
        BitcoinExchange(const BitcoinExchange &rhs);
        BitcoinExchange &operator=(const BitcoinExchange &rhs);
        
        std::map<std::string, float>    _priceHistory;
};