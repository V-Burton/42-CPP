#include "Cat.hpp"

Cat::Cat(){
	std::cout << GREEN << BOLD << "Cat default constructor called \n" << END;
	this->setType("Cat");
	this->_brain = new Brain();
}

Cat::Cat(Cat const &rhs) : Animal(rhs){
	std::cout << GREEN << BOLD << "Cat Copy constructor called \n" << END;
	*this = rhs;
}

Cat &Cat::operator=(Cat const &rhs){
	this->_type = rhs.getType();
	this->_brain = new Brain(*rhs._brain);
	return (*this);
}

Cat::~Cat(){
	delete this->_brain;
	std::cout << BOLD << RED << "Cat destructor called\n" << END;
}

void	Cat::makeSound() const{
	std::cout << "The Cat " << this->_type << " " << BOLD << "Meoooows\n" << END;
}
