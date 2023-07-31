#include "WrongCat.hpp"

WrongCat::WrongCat(){
	std::cout << GREEN << BOLD << "WrongCat default constructor called \n" << END;
	this->setType("WrongCat");
}

WrongCat::WrongCat(WrongCat const &rhs) : WrongAnimal(rhs){
	std::cout << GREEN << BOLD << " WrongCat Copy constructor called \n" << END;
	*this = rhs;
}

WrongCat &WrongCat::operator=(WrongCat const &rhs){
	this->_type = rhs.getType();
	return (*this);
}

WrongCat::~WrongCat(){
	std::cout << BOLD << RED << "WrongCat destructor called\n" << END;
}

void	WrongCat::makeSound() const{
	std::cout << "The WrongCat " << this->_type << " " << BOLD << "Wrong Meoooows\n" << END;
}
