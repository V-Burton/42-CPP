#include "PmergeMe.hpp"

int	main(int argc, char **argv){
	if (argc < 2){
		std::cerr << "Error: need arguments." << std::endl;
		return (1);
	}

	clock_t timeStart, timeEnd;
	double timeV;

	PmergeMe test = PmergeMe(argv);
	std::cout << "Before: ";
	for (int i = 1; i < argc; i++){
		std::cout << argv[i] << " ";
	}
	std::cout << std::endl;
	std::vector<int>::iterator begin = test.getVector().begin();
	std::vector<int>::iterator end = std::prev(test.getVector().end(), 1);
	timeStart = clock();
	test.sort(test.getVector(), begin, end);
	timeEnd = clock();
	std::list<int>::iterator beginL = test.getList().begin();
	std::list<int>::iterator endL = std::prev(test.getList().end(), 1);
	timeStart = clock();
	test.sort(test.getList(), beginL , endL);
	timeEnd = clock();
	timeV = static_cast<double>(timeEnd - timeStart) / CLOCKS_PER_SEC * 1000000;
	test.display(test.getVector());
	std::cout << "Time to precess a range of " << argc - 1 << " elements with std::vector<int> : " << timeV << " us" << std::endl;

	return (0);
}
