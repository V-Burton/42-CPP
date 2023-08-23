#include "FragTrap.hpp"

FragTrap::FragTrap(){
    this->_hPoint = 100;
    this->_ePoint = 100;
    this->_aDamage = 30;
    std::cout << "Default FragTrap constructor called." << std::endl;

}

FragTrap::FragTrap(std::string &name){
    this->_hPoint = 100;
    this->_ePoint = 100;
    this->_aDamage = 30;
    this->_name = name;
    std::cout << "FragTrap constructor called." << std::endl;
}

FragTrap::FragTrap(const FragTrap &rhs) : ClapTrap(rhs){
    std::cout << "FragTrap Copy constructor called" << std::endl;
    *this = rhs;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs){
	this->_name = rhs._name;
	this->_hPoint = rhs._hPoint;
	this->_ePoint = rhs._ePoint;
	this->_aDamage = rhs._aDamage;
	return (*this);
}

FragTrap::~FragTrap(){
        std::cout << BOLD << RED << "FragTrap destructor called." << END << std::endl;

}

void    FragTrap::highFivesGuys(void){
    std::cout << YELLOW << "High Fives! \n" << END;
}
