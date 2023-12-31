#include "PmergeMe.hpp"

int	main(int argc, char **argv){
	if (argc < 2){
		std::cerr << "Error: need arguments." << std::endl;
		return (1);
	}

	clock_t timeStart, timeEnd;
	double timeV, timeD;

	try{
		PmergeMe test = PmergeMe(argv);
		test.displayVector("Before:	");
		timeStart = clock();
		test.sortVector(0, argc - 1);
		timeEnd = clock();
		timeV = static_cast<double>(timeEnd - timeStart) / CLOCKS_PER_SEC * 1000000;
		test.displayVector("After:	");
		timeStart = clock();
		test.sortList(test.getList().begin(), test.getList().end());
		timeEnd = clock();
		test.displayList("After:	");
		timeD = static_cast<double>(timeEnd - timeStart) / CLOCKS_PER_SEC * 1000000;
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector<int> : " << timeV << " us" << std::endl;
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::list<int> : " << timeD << " us" << std::endl;
	}
	catch(std::exception &e){
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}

	return (0);
}
