#include "BitcoinExchange.hpp"

std::map<std::string, float> buildData(std::string inputData){
    std::ifstream data;
    std::map<std::string, float> priceHistory;
    data.open(inputData.c_str());
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
        priceHistory[key] = std::atof(value.c_str());
    }
    data.close();
    return (priceHistory);
}

int main(int argc, char **argv){
    
    std::map<std::string, float> priceHistoryBtc;
    if (argc != 2){
        std::cerr << RED << "Error: could not open file." << END << std::endl;
        return (1);
    }
    (void)argv;
    BitcoinExchange account;
    account.setData(buildData("data.csv"));
    account.displayValue(argv[1]);
    return (0);
}