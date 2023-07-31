#include "Cat.hpp"

Cat::Cat(){
	std::cout << GREEN << BOLD << "Cat default constructor called \n" << END;
	this->setType("Cat");
}

Cat::Cat(Cat const &rhs) : Animal(rhs){
	std::cout << GREEN << BOLD << " Cat Copy constructor called \n" << END;
	*this = rhs;
}

Cat &Cat::operator=(Cat const &rhs){
	this->_type = rhs.getType();
	return (*this);
}

Cat::~Cat(){
	std::cout << BOLD << RED << "Cat destructor called\n" << END;
}

void	Cat::makeSound() const{
	std::cout << "The Cat " << this->_type << " " << BOLD << "Meoooows\n" << END;
}
