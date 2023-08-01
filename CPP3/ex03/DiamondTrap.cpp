#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(){
    this->_hPoint = FragTrap::_hPoint;
    this->_ePoint = ScavTrap::_ePoint;
    this->_aDamage = FragTrap::_aDamage;
    std::cout << "Default DiamondTrap constructor called." << std::endl;

}

DiamondTrap::DiamondTrap(const std::string &name): ClapTrap(name + "_clap_name"){
    this->_hPoint = FragTrap::_hPoint;
    this->_ePoint = ScavTrap::_ePoint;
    this->_aDamage = FragTrap::_aDamage;
    this->_name = name;
    std::cout << "DiamondTrap constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &rhs)  : ClapTrap(), ScavTrap(), FragTrap(){
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
    *this = rhs;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs){
	this->_name = rhs._name;
	this->_hPoint = rhs._hPoint;
	this->_ePoint = rhs._ePoint;
	this->_aDamage = rhs._aDamage;
	return (*this);
}

DiamondTrap::~DiamondTrap(){
        std::cout << "DiamondTrap destructor called." << std::endl;

}

void	DiamondTrap::whoAmI(){
	std::cout << "My diamond name is: " << this->_name << " and my claptrap name is: " << ClapTrap::_name << "\n";
}
