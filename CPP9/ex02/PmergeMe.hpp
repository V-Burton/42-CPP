#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>

#define INSERTION 10

class PmergeMe{
	public:
		PmergeMe(char **argv);
		PmergeMe(const PmergeMe &rhs);
		PmergeMe &operator=(const PmergeMe &rhs);
		~PmergeMe();

		void	sortVector(int begin, int end);
		void	mergeVector(int begin, int middle, int end);
		void	insertionVector(int begin, int end);
		void	displayVector(std::string str) const;

		std::list<int>	&getList();

		void	insertionList();
		void	mergeList(std::list<int>::iterator begin, std::list<int>::iterator middle, std::list<int>::iterator end);
		void	sortList(std::list<int>::iterator	begin, std::list<int>::iterator	end);
		void	displayList(std::string str) const;

	private:
		PmergeMe();
		std::vector<int>	_vector;
		std::list<int>		_list;
};
