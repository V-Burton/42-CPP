#include "easyfind.hpp"

#include <iostream>
#include <list>
#include <vector>

int	main(){
	int	t[] = {1, 4, 6, 3, 4, 2, 9};
	int	target = 13;
	int target2 = 12;

	std::list<int> l1(t, t+7);
	std::vector<int> v1(t, t + sizeof(t)/sizeof(int));
	l1.push_back(12);

	if (easyfind(l1, target) != -1)
		std::cout << "There is an iteration of " << target << " in l1." << std::endl;
	else
		std::cout << target << " isn't in list l1.\n";
	if (easyfind(v1, target) != -1)
		std::cout << "There is an iteration of " << target << " in v1." << std::endl;
	else
		std::cout << target << " isn't in list v1.\n";
	if (easyfind(l1, target2) != -1)
		std::cout << "There is an iteration of " << target2 << " in l1." << std::endl;
	else
		std::cout << target2 << " isn't in list l1.\n";
	if (easyfind(v1, target2) != -1)
		std::cout << "There is an iteration of " << target2 << " in v1." << std::endl;
	else
		std::cout << target2 << " isn't in list v1.\n";
	return (0);
}
