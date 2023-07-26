#pragma once
#include <iostream>
#include <string>

class ClapTrap{

	public:
		ClapTrap();
		ClapTrap(std::string &name);
		ClapTrap(const ClapTrap &rhs);
		ClapTrap &operator=(const ClapTrap &rhs);
		~ClapTrap();

		std::string 	getName() const;
		void			setDamage(unsigned int damage);
		unsigned int	getDamage();
		unsigned int	getHealth();
		unsigned int	getEnergie();

		void        attack(const std::string &target);
		void        takeDamage(unsigned int amount);
		void        beRepaired(unsigned int amount);

	protected:
		std::string _name;
		int         _hPoint;
		unsigned int         _ePoint;
		unsigned int         _aDamage;
};