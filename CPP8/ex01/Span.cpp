#include "Span.hpp"

Span::Span(): _N(0){
	this->_tab = std::vector<int>();
}

Span::Span(unsigned int n): _N(n){
	this->_tab = std::vector<int>();
}

Span::Span(const Span &rhs){
	*this = rhs;
}

Span &Span::operator=(const Span &rhs){
	if (this == &rhs)
		return (*this);
	this->_N = rhs._N;
	this->_tab = rhs._tab;
	return (*this);
}

Span::~Span(){}

const char	*Span::TooManyNumberInSpan::what() const throw(){
	return ("Too many numbers in span.\n");
}

void	Span::addNumber(int n){
	if (_tab.size() < _N)
		_tab.push_back(n);
	else
		throw Span::TooManyNumberInSpan();
}

void Span::addMultipleNumber(int first, int last){
	srand(time(0));
	for(int i = first; i < last; i++)
		this->addNumber(rand());
}

int	Span::shortestSpan() const {
	if (_tab.size() == 0)
		return (std::cout << "_tab is empty : ", -1);
	std::vector<int> copy = _tab;
	std::sort(copy.begin(), copy.end());
	std::vector<int>::const_iterator it = copy.begin();
	int	previousValue = *it++;
	int diff = *it - previousValue;
	int shortestDiff = diff;

	for(; it != copy.end(); it++){
		diff = *it - previousValue;
		previousValue = *it;
		if (diff < shortestDiff){
			shortestDiff = diff;
		}
	}
	return (shortestDiff);
}

int	Span::longestSpan() const {
	if (_tab.size() == 0)
		return (std::cout << "_tab is empty : ", -1);
	std::vector<int> copy = _tab;
	std::sort(copy.begin(), copy.end());
	std::vector<int>::const_iterator it = copy.begin();
	int	previousValue = *it++;
	int diff = *it - previousValue;
	int longestDiff = diff;

	for(; it != copy.end(); it++){
		diff = *it - previousValue;
		if (diff > longestDiff)
			longestDiff = diff;
	}
	return (longestDiff);
}




