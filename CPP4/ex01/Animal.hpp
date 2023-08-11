#pragma once
#include <string>
#include <iostream>

#define END				"\033[0m"
#define BOLD			"\033[1m"
#define UNDERLINE		"\033[4m"
#define BLUE			"\033[34m"
#define YELLOW			"\033[33m"
#define CYAN			"\033[36m"
#define GREEN			"\033[32m"
#define RED				"\033[31m"

class Animal{

	public:
		Animal();
		Animal(const Animal &rhs);
		Animal &operator=(const Animal &rhs);
		virtual ~Animal();

		std::string getType() const;
		void	setType(std::string name);
		virtual void	makeSound() const;

	protected:
		std::string _type;
};
