#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice"){}

Ice::Ice(const Ice &rhs) : AMateria(rhs){
	*this = rhs;
}

Ice &Ice::operator=(const Ice &rhs){
	this->_type = rhs._type;
	return (*this);
}

Ice::~Ice(){}

AMateria *Ice::clone() const{
	Ice *clone;

	clone = new Ice(*this);
	return (clone);
}

void	Ice::use(ICharacter &target){
	std::cout << "* shoots an ice ball at " << target.getName() << " *\n";
}
