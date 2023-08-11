#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	Animal *array[10];
	for(int i = 0; i < 10; i++){
		if (i < 5)
			array[i] = new Dog();
		else
			array[i] = new Cat();
		array[i]->makeSound();
	}
	for (int i = 0; i < 10; i++){
		array[i]->makeSound();
		delete array[i];
	}
	return 0;
}
