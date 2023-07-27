#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _hPoint(10), _ePoint(10), _aDamage(0){
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name):_name(name), _hPoint(10), _ePoint(10), _aDamage(0){
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &rhs){
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs){
	this->_name = rhs._name;
	this->_hPoint = rhs._hPoint;
	this->_ePoint = rhs._ePoint;
	this->_aDamage = rhs._aDamage;
	return (*this);
}

ClapTrap::~ClapTrap(){
	std::cout << "Destructor called" << std::endl;
}

/*			Functions			*/

std::string	ClapTrap::getName() const {
	return (this->_name);
}

void	ClapTrap::setDamage(unsigned int damage){
	this->_aDamage = damage;
}

unsigned	int	ClapTrap::getDamage(){
	return (this->_aDamage);
}

unsigned	int	ClapTrap::getHealth(){
	return (this->_hPoint);
}

unsigned	int	ClapTrap::getEnergie(){
	return (this->_ePoint);
}

void	ClapTrap::takeDamage(unsigned int amount){
	if (this->_hPoint <= 0){
		std::cout << this->_name << " is dead..." << std::endl;
		this->_hPoint = 0;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage..." << std::endl;
	if (amount > (unsigned int)this->_hPoint)
		this->_hPoint = 0;
	else
		this->_hPoint -= amount;
}

void	ClapTrap::attack(const std::string &target){
	if (this->_hPoint <= 0){
		std::cout << this->_name << " is dead..." << std::endl;
		return ;
	}
	if (this->_ePoint <= 0){
		std::cout << this->_name << "Don't have enought energy to perform any action" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_aDamage << " points of damage!" << std::endl;
	this->_ePoint--;
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (this->_hPoint <= 0){
		std::cout << this->_name << " is dead..." << std::endl;
		return ;
	}
	if (this->_ePoint <= 0){;
		std::cout << this->_name << "Don't have enought energy to perform any action" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " gets " << amount << " hit point by Repairing itself" << std::endl;
	this->_hPoint += amount;
	this->_ePoint--;
}