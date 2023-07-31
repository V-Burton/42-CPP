#include "Dog.hpp"

Dog::Dog(){
	std::cout << GREEN << BOLD << "Dog default constructor called \n" << END;
	this->setType("dog");
}

Dog::Dog(Dog const &rhs) : Animal(rhs) {
	std::cout << GREEN << BOLD << " Dog Copy constructor called \n" << END;
	*this = rhs;
}

Dog &Dog::operator=(Dog const &rhs){
	this->_type = rhs.getType();
	return (*this);
}

Dog::~Dog(){
		std::cout << BOLD << RED << "Dog destructor called\n" << END;
}

void	Dog::makeSound() const{
	std::cout << "The dog " << this->_type << " " << BOLD << "Baaaaark\n" << END;
}
