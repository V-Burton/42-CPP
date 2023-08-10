#pragma once

#include "AMateria.hpp"

class Ice: public AMateria{

	public:
		Ice();
		Ice(const Ice &rhs);
		Ice &operator=(const Ice &rhs);
		~Ice();

		AMateria	*clone() const;
		void		use(ICharacter &target);
};
