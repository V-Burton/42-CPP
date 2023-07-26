#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
    this->_hPoint = 100;
    this->_ePoint = 50;
    this->_aDamage = 20;
    std::cout << "Default ScavTrap constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string &name){
    this->_name = name;
    this->_hPoint = 100;
    this->_ePoint = 50;
    this->_aDamage = 20;
    std::cout << "ScavTrap constructor called." << std::endl;
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap destructor called." << std::endl;
}

void    ScavTrap::guardGate(){
    std::cout << this->_name << " is now in Gate Keeper mode." << std::endl;
}