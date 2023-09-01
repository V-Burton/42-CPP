#pragma once

#include <iostream>
#include "algorithm"

template<typename T>
void	display(T value){
	typename T::iterator it;
	for (it = value.begin(); it != value.end(); it++)
		std::cout << (*it) << ", ";
	std::cout << std::endl;
}

template <typename T>
int	easyfind(T contener, int value){
	typename T::iterator it;

	it = std::find(contener.begin(), contener.end(), value);
	if (it != contener.end())
		return (*it);
	else
		return (-1);
}
