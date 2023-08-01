#pragma once
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public virtual ClapTrap, public virtual ScavTrap, public virtual FragTrap{

    public:
        DiamondTrap(const std::string &name);
        DiamondTrap(const DiamondTrap &rhs);
        DiamondTrap &operator=(const DiamondTrap &rhs);
        ~DiamondTrap();


		void		whoAmI();

		using		ScavTrap::attack;

    private :
        std::string _name;
        DiamondTrap();
};
