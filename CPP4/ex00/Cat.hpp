#pragma once
# include "Animal.hpp"

class Cat : public Animal{

	public:
		Cat();
		Cat(Cat const &rhs);
		Cat &operator=(Cat const &rhs);
		~Cat();

		void	makeSound() const;
};
