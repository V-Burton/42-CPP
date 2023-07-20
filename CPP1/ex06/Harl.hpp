#pragma once
#include <string>
#include <iostream>

#define END			"\033[0m"
#define BOLD		"\033[1m"
#define UNDERLINE	"\033[4m"

class Harl
{
	public:
		Harl();
		~Harl();
		void    complain(std::string level);
		
	private:
		std::string _levels[4];
		void    (Harl::*_fctLevel[4])();

		void    debug(void);
		void    info(void);
		void    warning(void);
		void    error(void);
};