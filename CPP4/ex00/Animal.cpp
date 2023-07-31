#include "Animal.hpp"

Animal::Animal(){
	std::cout << GREEN << BOLD << "Animal default constructor called \n" << END;
	this->_type = "Empty";
}

Animal::Animal(const Animal &rhs){
	std::cout << GREEN << BOLD << " Animal Copy constructor called \n" << END;
	*this = rhs;
}

Animal &Animal::operator=(const Animal &rhs){
	this->_type = rhs.getType();
	return (*this);
}

Animal::~Animal(){
		std::cout << BOLD << RED << "Animal destructor called\n" << END;
}

std::string Animal::getType() const{
	return (this->_type);
}

void	Animal::setType(std::string name){
	this->_type = name;
}

void	Animal::makeSound() const{
	std::cout << "Random Animal make " << BOLD << "AAARFRGEHHHH \n" << END;
}
