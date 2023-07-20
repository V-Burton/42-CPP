#include "Harl.hpp"

int main(void){
    Harl    harl;

    std::cout << UNDERLINE << BOLD << "Debug:" << END << std::endl;
    std::cout << "\t";
    harl.complain("DEBUG");
    std::cout << std::endl;
    std::cout << UNDERLINE << BOLD << "Info:" << END << std::endl;
    std::cout << "\t";
    harl.complain("INFO");
    std::cout << std::endl;
    std::cout << UNDERLINE << BOLD << "Warning:" << END << std::endl;
    std::cout << "\t";
    harl.complain("WARNING");
    std::cout << std::endl;
    std::cout << UNDERLINE << BOLD << "Error:" << END << std::endl;
    std::cout << "\t";
    harl.complain("ERROR");
    std::cout << std::endl;
    std::cout << UNDERLINE << BOLD << "No level:" << END << std::endl;
    std::cout << "\t";
    harl.complain("No Level");
    std::cout << std::endl;
    return (0);
}