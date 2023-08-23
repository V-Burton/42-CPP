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

ScavTrap::ScavTrap(const ScavTrap &rhs) : ClapTrap(rhs){
    std::cout << "ScavTrap Copy constructor called" << std::endl;
    *this = rhs;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs){
	this->_name = rhs._name;
	this->_hPoint = rhs._hPoint;
	this->_ePoint = rhs._ePoint;
	this->_aDamage = rhs._aDamage;
	return (*this);
}

ScavTrap::~ScavTrap(){
    std::cout << BOLD << RED << "ScavTrap destructor called." << END << std::endl;
}

void    ScavTrap::attack(const std::string &target){
    if (this->ClapTrap::getHealth() <= 0){
        std::cout << this->ClapTrap::getName() << " is dead \n";
        return ;
    }
    if (this->_ePoint <= 0){
        std::cout << this->ClapTrap::getName() << " don't have any energie left \n";
        return ;
    }
    std::cout<< "ScavTrap " << this->ClapTrap::getName() << " attacks " << target << " causing " << this->_aDamage << " points of damage!" << std::endl;
    return ;
}

void    ScavTrap::guardGate(){
    std::cout << YELLOW << this->_name << " is now in Gate Keeper mode." << END << std::endl;
}
