#pragma once
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public virtual ClapTrap, public FragTrap, public ScavTrap{

    public:
        DiamondTrap(const std::string &name);
        DiamondTrap(const DiamondTrap &rhs);
        DiamondTrap &operator=(const DiamondTrap &rhs);
        ~DiamondTrap();

        void highFivesGuys(void);

    private : 
        std::string _name;
        DiamondTrap();
};