#pragma once

#include <string>
#include "ICharacter.hpp"

#define NB_SLOT 4

class Character : public ICharacter{

	public:
		Character();
		Character(std::string name);
		Character(const Character &rhs);
		Character	&operator=(const Character &rhs);
		~Character();

		const std::string	&getName() const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);

	private:
		AMateria 	*_inventory[NB_SLOT];
		std::string	_name;
};
