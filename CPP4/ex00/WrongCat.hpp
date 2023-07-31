#pragma once
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{

	public:
		WrongCat();
		WrongCat(WrongCat const &rhs);
		WrongCat &operator=(WrongCat const &rhs);
		~WrongCat();

		void	makeSound() const;
};
