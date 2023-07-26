#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
    public:
        ScavTrap();
        ScavTrap(std::string &name);
        // ScavTrap(const ScavTrap &rhs) : ClapTrap(const ClapTrap &rhs){}
        // ScavTrap &operator=(const ScavTrap &rhs);
        ~ScavTrap();

        void    guardGate();
};