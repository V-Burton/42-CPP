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

		// void	sort(int begin, int end);
		// void	merge(int begin, int middle, int end);
		// void	insertion(int begin, int end);
		// void	display() const;

		std::vector<int>	&getVector();
		std::list<int>		&getList();

		template<typename Container>
		void	sort(Container& container, typename Container::iterator begin, typename Container::iterator end);
		template<typename Container>
		void	insertion(Container &container, typename Container::iterator begin, typename Container::iterator end);
		template<typename Container>
		void	merge(Container &container, typename Container::iterator begin, typename Container::iterator middle, typename Container::iterator end);
		template<typename Container>
		void	display(Container &container);

	private:
		PmergeMe();
		std::vector<int>	_vector;
		std::list<int>		_list;


};
