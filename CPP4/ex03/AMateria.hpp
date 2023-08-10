#pragma once

#include <string>
#include <iostream>

class ICharacter;

class AMateria
{
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria &rhs);
		AMateria &operator=(const AMateria &rhs);
		virtual ~AMateria();

		std::string const & getType() const; //Returns the materia type

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

	protected:
		std::string	_type;
};
