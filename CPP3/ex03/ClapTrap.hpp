#pragma once
#include <iostream>
#include <string>

#define END				"\033[0m"
#define BOLD			"\033[1m"
#define UNDERLINE		"\033[4m"
#define BLUE			"\033[34m"
#define YELLOW			"\033[33m"
#define CYAN			"\033[36m"
#define GREEN			"\033[32m"
#define RED				"\033[31m"

class ClapTrap{

	public:
		ClapTrap();
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &rhs);
		ClapTrap &operator=(const ClapTrap &rhs);
		~ClapTrap();

		std::string 	getName() const;
		void			setDamage(unsigned int damage);
		unsigned int	getDamage();
		unsigned int	getHealth();
		unsigned int	getEnergie();

		virtual void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	protected:
		std::string 		_name;
		int         		_hPoint;
		unsigned int         _ePoint;
		unsigned int         _aDamage;
};
