#include "Harl.hpp"

Harl::Harl(){
    _levels[0] = "DEBUG";
    _levels[1] = "INFO";
    _levels[2] = "WARNING";
    _levels[3] = "ERROR";
    _fctLevel[0] = &Harl::debug;
    _fctLevel[1] = &Harl::info;
    _fctLevel[2] = &Harl::warning;
    _fctLevel[3] = &Harl::error;

}

Harl::~Harl(){}

void    Harl::debug(void){
    std::cout << UNDERLINE << BOLD << "[ DEBUG ]" << END << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void    Harl::info(void){
    std::cout << UNDERLINE << BOLD << "[ INFO ]" << END << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harl::warning(void){
    std::cout << UNDERLINE << BOLD << "[ WARNING ]" << END << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void    Harl::error(void){
    std::cout << UNDERLINE << BOLD << "[ ERROR ]" << END << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string level){
    int numLevel = 0;
    for(int i = 0; i < 4 ; i++){
        if(level != this->_levels[i])
            numLevel++;
        else
            break ;
    }
    switch(numLevel){
        case 0: case 1: case 2: case 3:
        while(numLevel < 4){
            (this->*_fctLevel[numLevel])();
            numLevel++;
        }
        default:
            std::cerr << "Harl cannot complain since this : '" << level << "' doesn't exist" << std::endl;

    }
}