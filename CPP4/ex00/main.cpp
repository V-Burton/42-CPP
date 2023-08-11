#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrong = new WrongAnimal();
	const WrongAnimal* wrongMeta = new WrongCat();
	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	std::cout << wrongMeta->getType() << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	wrong->makeSound();
	wrongMeta->makeSound();

	delete meta;
	delete i;
	delete j;
	delete wrongMeta;
	delete wrong;
	return 0;
}
