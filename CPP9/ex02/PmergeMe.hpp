#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

#define INSERTION 2

class PmergeMe{
	public:
		PmergeMe(char **argv);
		PmergeMe(const PmergeMe &rhs);
		PmergeMe &operator=(const PmergeMe &rhs);
		~PmergeMe();

		void	sort(int begin, int end);
		void	merge(int begin, int middle, int end);
		void	insertion(int begin, int end);
		void	display() const;

	private:
		PmergeMe();
		std::vector<int>	_vector;
		std::list<int>		_list;


};
