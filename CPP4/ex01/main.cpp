#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	Dog basic;
	{
	Dog tmp = basic;
	}
	Animal *array[10];
	for(int i = 0; i < 10; i++){
		if (i < 5)
			array[i] = new Dog();
		else
			array[i] = new Cat();
	}
	for (int i = 0; i < 10; i++)
		delete array[i];
	std::cout << "Delete basic Dog\n";
	return 0;
}
