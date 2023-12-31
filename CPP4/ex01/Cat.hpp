#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{

	public:
		Cat();
		Cat(Cat const &rhs);
		Cat &operator=(Cat const &rhs);
		virtual ~Cat();

		void	makeSound() const;

	private:
		Brain	*_brain;
};
