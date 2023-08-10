#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure"){}

Cure::Cure(const Cure &rhs) : AMateria(rhs){
	*this = rhs;
}

Cure &Cure::operator=(const Cure &rhs){
	this->_type = rhs._type;
	return (*this);
}

Cure::~Cure(){}

AMateria *Cure::clone() const{
	Cure *clone;

	clone = new Cure(*this);
	return (clone);
}

void	Cure::use(ICharacter &target){

	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
