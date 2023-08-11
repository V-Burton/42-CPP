#include "Brain.hpp"

Brain::Brain(){
	std::cout << BOLD << GREEN << "Default Brain constructor called \n" << END;
}

Brain::Brain(const Brain &rhs){
		std::cout << BOLD << GREEN << "Copy Brain constructor called \n" << END;
		*this = rhs;
}

Brain &Brain::operator=(const Brain &rhs){
	for(int i = 0; i < NB_IDEAS; i++)
		this->_ideas[i] = rhs._ideas[i];
	return (*this);
}


Brain::~Brain(){
		std::cout << BOLD << RED << "Brain destructor called\n" << END;

}
