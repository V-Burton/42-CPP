#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{

	public:
		Dog();
		Dog(Dog const &rhs);
		Dog &operator=(Dog const &rhs);
		virtual ~Dog();

		void	makeSound() const;

	private:
		Brain	*_brain;
};
