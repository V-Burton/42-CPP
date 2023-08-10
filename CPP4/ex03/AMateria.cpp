#include "AMateria.hpp"

AMateria::AMateria(): _type("Unknown"){}

AMateria::AMateria(std::string const & type){
	this->_type = type;
}

AMateria::AMateria(const AMateria &rhs){
	*this = rhs;
}

AMateria &AMateria::operator=(const AMateria &rhs){
	this->_type = rhs._type;
	return (*this);
}

AMateria::~AMateria(){}

std::string const &AMateria::getType() const{
	return (this->_type);
}

void	AMateria::use(ICharacter& target){
	(void) target;
}
