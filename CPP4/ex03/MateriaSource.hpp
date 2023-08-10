#pragma once

#include <string>
#include <iostream>
#include "IMateriaSource.hpp"

# define NB_SLOT	4

#define GREEN	"\033[32m"
#define END		"\033[0m"

class MateriaSource: public IMateriaSource{

	public:
		MateriaSource();
		MateriaSource(const MateriaSource &rhs);
		MateriaSource &operator=(const MateriaSource &rhs);
		~MateriaSource();

		void		learnMateria(AMateria *src);
		AMateria 	*createMateria(std::string const & type);

	private:
		AMateria	*_inventory[NB_SLOT];

};
