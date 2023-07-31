#pragma once
#include "Animal.hpp"

class Dog : public Animal{

	public:
		Dog();
		Dog(Dog const &rhs);
		Dog &operator=(Dog const &rhs);
		~Dog();

		void	makeSound() const;
};
