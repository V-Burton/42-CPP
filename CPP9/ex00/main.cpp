#include "BitcoinExchange.hpp"

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
    if (mounth < 1 || mounth > 12){
        std::cerr << RED << "Error: Impossible date" << END << std::endl;
        return (1);
    }
    if (day < 1 || day > days[mounth]){
        std::cerr << RED << "Error: Impossible date" << END << std::endl;
        return (1);
    }
    return (0);
}

std::map<std::string, float> buildAccount(std::string inputFile){
    std::map<std::string, float>    account;
    std::ifstream input(inputFile.c_str());
    if (!input.is_open()){
		throw std::ios_base::failure(std::string("BitcoinExchange: ") + inputFile);
    }
    std::string buffer, key, value;
    while(std::getline(input, buffer)){
        if (buffer == "date | value")
            continue;
        std::istringstream iss(buffer);
        std::getline(iss, key, ' ');
        if (checkDate(key)){
            throw std::runtime_error("Error while building the map");
        }
        std::getline(iss, value, ' ');
        if (value != "|"){
            throw std::runtime_error("Error while building the map");
        }
        std::getline(iss, value, ' ');
        if (!checkValue(key)){
            throw std::runtime_error("Error while building the map");
        }
        double fValue =  checkValue(value);
        if (fValue < 0 || fValue > 1000){
            throw std::runtime_error("Error while building the map");
        }
        account[key] = fValue;
    }
    input.close();
    return (account);
}

int main(int argc, char **argv){
    
    std::map<std::string, float> priceHistoryBtc;
    // std::string data = argv[1];
    if (argc != 2){
        std::cerr << "Error: could not open file." << std::endl;
        return (1);
    }
    (void)argv;
    BitcoinExchange test;
    try{
        priceHistoryBtc = buildAccount(argv[1]);
    }
    catch(std::exception &e){
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    // std::ofstream data;
    // data.open("data.csv");
    // if (!data.is_open()){
    //     std::cerr << "Error while opening data file." << std::endl;
    //     return (1);
    // }

    return (0);
}