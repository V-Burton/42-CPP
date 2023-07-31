#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	std::cout << GREEN << BOLD << "WrongAnimal default constructor called \n" << END;
	this->_type = "Empty";
}

WrongAnimal::WrongAnimal(const WrongAnimal &rhs){
	std::cout << GREEN << BOLD << " WrongAnimal Copy constructor called \n" << END;
	*this = rhs;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs){
	this->_type = rhs.getType();
	return (*this);
}

WrongAnimal::~WrongAnimal(){
		std::cout << BOLD << RED << "WrongAnimal destructor called\n" << END;
}

std::string WrongAnimal::getType() const{
	return (this->_type);
}

void	WrongAnimal::setType(std::string name){
	this->_type = name;
}

void	WrongAnimal::makeSound() const{
	std::cout << "Random WrongAnimal make " << BOLD << "Wrong AAARFRGEHHHH \n" << END;
}
