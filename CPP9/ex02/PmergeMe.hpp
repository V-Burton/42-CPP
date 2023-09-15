#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

#define INSERTION 24

class PmergeMe{
	public:
		PmergeMe(char **argv);
		PmergeMe(const PmergeMe &rhs);
		PmergeMe &operator=(const PmergeMe &rhs);
		~PmergeMe();

		void	sortList(std::list<int>::iterator begin, std::list<int>::iterator end);
		void	mergeList(std::list<int>::iterator begin, std::list<int>::iterator middle, std::list<int>::iterator end);
		void	insertionList(std::list<int>::iterator begin, std::list<int>::iterator end);
		void	displayList() const;

		void	sortVector(int begin, int end);
		void	mergeVector(int begin, int middle, int end);
		void	insertionVector(int begin, int end);
		void	displayVector() const;

	private:
		PmergeMe();
		std::vector<int>	_vector;
		std::list<int>		_list;


};
