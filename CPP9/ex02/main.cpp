#include "PmergeMe.hpp"

int	main(int argc, char **argv){
	if (argc < 2){
		std::cerr << "Error: need arguments." << std::endl;
		return (1);
	}

	clock_t timeStart, timeEnd;
	double timeV, timeD;

	PmergeMe test = PmergeMe(argv);
	std::cout << "Before: ";
	for (int i = 1; i < argc; i++){
		std::cout << argv[i] << " ";
	}
	std::cout << std::endl;

	timeStart = clock();
	test.sortVector(0, argc - 1);
	timeEnd = clock();
	timeV = static_cast<double>(timeEnd - timeStart) / CLOCKS_PER_SEC * 1000000;
	std::cout << "Before: ";
	test.displayVector();
	std::cout << std::endl;
	timeStart = clock();
	test.sortDeque(0, argc - 1);
	timeEnd = clock();
	timeD = static_cast<double>(timeEnd - timeStart) / CLOCKS_PER_SEC * 1000000;
	std::cout << "Time to precess a range of " << argc - 1 << " elements with std::vector<int> : " << timeV << " us" << std::endl;
	std::cout << "Time to precess a range of " << argc - 1 << " elements with std::deque<int> : " << timeD << " us" << std::endl;

	return (0);
}
