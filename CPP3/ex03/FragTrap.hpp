#pragma once
#include "ClapTrap.hpp"

class FragTrap: public virtual ClapTrap {

    public:
        FragTrap();
        FragTrap(std::string &name);
        FragTrap(const FragTrap &rhs);
        FragTrap &operator=(const FragTrap &rhs);
        ~FragTrap();

        void highFivesGuys(void);
};
