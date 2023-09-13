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

void	PmergeMe::insertion(int begin, int end){
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

void	PmergeMe::merge(int begin, int middle, int end){
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

void	PmergeMe::sort(int begin, int end){
	int	middle = (begin + end) / 2;
	if (end - begin > INSERTION){
		sort(begin, middle + 1);
		sort(middle + 1, end);
		merge(begin, middle, end);
	}
	else
		insertion(begin, end);
}

void	PmergeMe::display() const{
	std::cout << "After:	";
	for(__SIZE_TYPE__ i = 0; i < _vector.size(); i++)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;
}
