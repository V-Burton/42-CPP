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

#define NB_IDEAS 100

class Brain{

	public:
		Brain();
		Brain(const Brain &rhs);
		Brain &operator=(const Brain &rhs);
		~Brain();

	private:
		std::string _ideas[NB_IDEAS];
};
