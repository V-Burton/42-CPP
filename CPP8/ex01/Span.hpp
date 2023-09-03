#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span{
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &rhs);
		Span &operator=(const Span &rhs);
		~Span();

		class TooManyNumberInSpan: public std::exception{
			const char *what() const throw();
		};

		void	addNumber(int n);
		void 	addMultipleNumber(int first, int last);
		int		shortestSpan() const;
		int		longestSpan() const;

	private:
		unsigned int		_N;
		std::vector<int>	_tab;
};
