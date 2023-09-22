#include "BitcoinExchange.hpp"

int checkDate(std::string date);
double checkValue(const std::string& str);

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::~BitcoinExchange(){}

void    BitcoinExchange::setAccount(std::multimap<std::string, float> account){
    this->_account = account;
}

void    BitcoinExchange::setData(std::map<std::string, float> dataFile){
    this->_priceHistory = dataFile;
}

void    BitcoinExchange::displayValue(std::string inputFile) const{
    std::ifstream input(inputFile.c_str());
    if (!input.is_open()){
		throw std::ios_base::failure(std::string("BitcoinExchange: ") + inputFile);
    }
    std::string buffer, key, value;
    while(std::getline(input, buffer)){
        if (buffer == "date | value" || buffer.length() == 0)
            continue;
        std::istringstream iss(buffer);
        std::getline(iss, key, ' '); 
        if (checkDate(key) == 1)
            continue;
        std::getline(iss, value, ' ');
        try {
            if (value != "|")
                throw std::runtime_error("Error: not a good format");
        }
        catch (std::exception &e){
            std::cerr << RED << e.what() << END << std::endl;
            continue;
        }
        std::getline(iss, value, ' ');
        double fValue =  checkValue(value);
        try {
            if (fValue == -1)
                 throw std::runtime_error("Error: bad input.");
            else if (fValue < 0)
                throw std::runtime_error("Error: not a positive number.");
            else if (fValue > 1000)
                throw std::runtime_error("Error: Too large a number.");
        }
        catch (std::exception &e){
            std::cerr << RED << e.what() << END << std::endl;
            continue;
        }
        std::map<std::string, float>::const_iterator it = this->_priceHistory.lower_bound(key);
        if (it->first != key && key != "2009-01-01")
            it--;
        std::cout <<  key << " => " << fValue << " = "<< it->second * fValue << std::endl;
    }
}

double checkValue(const std::string& str) {
    char* end;
    double value;
    value = strtod(str.c_str(), &end);
    if (*end == '\0')
        return (value);
    return (-1);
}

int checkDate(std::string date){
    if (date.size() != 10){
        std::cerr << RED << "Error: date format" << END << std::endl;
        return (1);
    }
    if (date[4] != '-' || date[7] != '-'){
        std::cerr << RED << "Error: date format" << END << std::endl;
        return (1);
    }
    int day, mounth, year;
    year = atoi(date.c_str());
    mounth = atoi(date.c_str() + 5);
    day = atoi(date.c_str() + 8);
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 4 == 0)
        days[1] = 29;
    if (mounth < 1 || mounth > 12 || day < 1 || day > days[mounth] || year < 2009){
        std::cerr << RED << "Error: bad input => " << date << END << std::endl;
        return (1);
    }
    // if (day < 1 || day > days[mounth]){
    //     std::cerr << RED << "Error: bad input => " << date << END << std::endl;
    //     return (1);
    // }
    return (0);
}
