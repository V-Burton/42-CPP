#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(char **argv){
	for (int i = 1; argv[i] != NULL; i++){
		int	convert = atoi(argv[i]);
		_vector.push_back(convert);
		_list.push_back(convert);
	}
}

PmergeMe::PmergeMe(const PmergeMe &rhs){
	*this = rhs;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs){
	this->_vector = rhs._vector;
	this->_list = rhs._list;
	return (*this);
}

PmergeMe::~PmergeMe(){}

void	PmergeMe::insertionVector(int begin, int end){
	for (int i = 0; i < end - 1; i++){
		int buffer = _vector[i + 1];
		int j = i + 1;
		while (j > begin && buffer < _vector[j - 1]){
			_vector[j] = _vector[j - 1];
			j--;
		}
		_vector[j] = buffer;
	}
}

void	PmergeMe::mergeVector(int begin, int middle, int end){
	int	iRight = 0, iLeft = 0, first = middle - begin + 1, second = end - middle;
	std::vector<int> vectorLeft(_vector.begin() + begin, _vector.begin() + middle + 1 );
	std::vector<int> vectorRight(_vector.begin() + middle + 1, _vector.begin() + end + 1);
	for (int i = begin; i < end; i++){
		if (iRight == second){
			_vector[i] = vectorLeft[iLeft];
			iLeft++;
		}
		else if(iLeft == first){
			_vector[i] = vectorRight[iRight];
			iRight++;
		}
		else if (vectorRight[iRight] > vectorLeft[iLeft]){
			_vector[i] = vectorLeft[iLeft];
			iLeft++;
		}
		else{
			_vector[i] = vectorRight[iRight];
			iRight++;
		}
	}
}

void	PmergeMe::sortVector(int begin, int end){
	int	middle = (begin + end) / 2;
	if (end - begin > INSERTION){
		sortVector(begin, middle + 1);
		sortVector(middle + 1, end);
		mergeVector(begin, middle, end);
	}
	else
		insertionVector(begin, end);
}

void	PmergeMe::displayVector() const{
	std::cout << "After:	";
	for(__SIZE_TYPE__ i = 0; i < _vector.size(); i++)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;
}

void	PmergeMe::insertionList(std::list<int>::iterator begin, std::list<int>::iterator end){
	for (int i = 0; i < end - 1; i++){
		int buffer = _list[i + 1];
		int j = i + 1;
		while (j > begin && buffer < _list[j - 1]){
			_list[j] = _list[j - 1];
			j--;
		}
		_list[j] = buffer;
	}
}

void	PmergeMe::mergeList(std::list<int>::iterator begin, std::list<int>::iterator middle, std::list<int>::iterator end{
	int	iRight = 0, iLeft = 0, first = middle - begin + 1, second = end - middle;
	std::list<int> listLeft(_list.begin() + begin, _list.begin() + middle + 1 );
	std::list<int> listRight(_list.begin() + middle + 1, _list.begin() + end + 1);
	for (int i = begin; i < end; i++){
		if (iRight == second){
			_list[i] = listLeft[iLeft];
			iLeft++;
		}
		else if(iLeft == first){
			_list[i] = listRight[iRight];
			iRight++;
		}
		else if (listRight[iRight] > listLeft[iLeft]){
			_list[i] = listLeft[iLeft];
			iLeft++;
		}
		else{
			_list[i] = listRight[iRight];
			iRight++;
		}
	}
}

void	PmergeMe::sortList(std::list<int>::iterator begin, std::list<int>::iterator end){
	std::list<int>::iterator	middle = _list.begin() + _list.size() / 2 + 1;
	if (end - begin > INSERTION){
		sortList(begin, middle + 1);
		sortList(middle + 1, end);
		mergeList(begin, middle, end);
	}
	else
		insertionList(begin, end);
}

void	PmergeMe::displayList() const{
	std::cout << "After:	";
	for(__SIZE_TYPE__ i = 0; i < _list.size(); i++)
		std::cout << _list[i] << " ";
	std::cout << std::endl;
}
