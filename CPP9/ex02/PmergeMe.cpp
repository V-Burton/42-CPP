#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(char **argv){
	for (int i = 1; argv[i] != NULL; i++){
		for (int y = 0; argv[i][y] != '\0'; y++){
			if (isdigit(argv[i][y]) == 0 && argv[i][y] != '\0' && argv[i][y] != '+')
				throw std::runtime_error(argv[i]);
		}
		int	convert = atoi(argv[i]);
		if (convert < 0)
			throw std::runtime_error(argv[i]);
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

std::list<int>	&PmergeMe::getList(){
	return (_list);
}

void PmergeMe::insertionList() {
    std::list<int>::iterator it = _list.begin();
    ++it;
    while (it != _list.end()) {
        std::list<int>::iterator current = it++;
		std::list<int>::iterator prev = current;
		prev--;
        while (current != _list.begin() && *current < *prev) {
            std::iter_swap(current, prev);
			if (prev != _list.begin()){
				current--;
				prev--;
			}
        }
    }
}

void	PmergeMe::mergeList(std::list<int>::iterator begin, std::list<int>::iterator middle, std::list<int>::iterator end){
	if(begin == end)
		return ;

	std::list<int> listLeft;
	std::list<int> listRight;
	std::list<int>::iterator it;
	for (it = begin; it != middle; it++)
		listLeft.push_back(*it);

	for(it = middle; it != end; it++)
		listRight.push_back(*it);
	
	std::list<int>::iterator iLeft = listLeft.begin();
	std::list<int>::iterator iRight = listRight.begin();

	for (it = begin; it != end; it++){
		if (iRight == listRight.end()){
			*it = *iLeft;
			iLeft++;
		}
		else if(iLeft == listLeft.end()){
			*it = *iRight;
			iRight++;
		}
		else if (*iRight > *iLeft){
			*it = *iLeft;
			iLeft++;
		}
		else{
			*it = *iRight;
			iRight++;
		}
	}
}

void	PmergeMe::sortList(std::list<int>::iterator	begin, std::list<int>::iterator	end){
	std::list<int>::iterator	middle = begin;
	for (int i = (std::distance(begin, end) / 2) + 1; i > 0; i--){
		middle++;
	}
	if (std::distance(begin, end) > INSERTION){
		sortList(begin, middle);
		sortList(middle, end);
		mergeList(begin, middle, end);
	}
	else
		insertionList();
}

void	PmergeMe::displayList(std::string str) const{
	std::cout << str;
	for(std::list<int>::const_iterator it = _list.begin(); it != _list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	PmergeMe::insertionVector(int begin, int end){
	for (int i = begin + 1; i < end; i++){
		int buffer = _vector[i];
		int j = i;
		while (j > begin && buffer < _vector[j - 1]){
			_vector[j] = _vector[j - 1];
			j--;
		}
		_vector[j] = buffer;
	}
}

void	PmergeMe::mergeVector(int begin, int middle, int end){
	int	iRight = 0, iLeft = 0, first = middle - begin, second = end - middle;
	std::vector<int> vectorLeft(_vector.begin() + begin, _vector.begin() + middle + 1);
	std::vector<int> vectorRight(_vector.begin() + middle, _vector.begin() + end + 1);
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
	int	middle = (begin + end) / 2 + 1;
	if (end - begin > INSERTION){
		sortVector(begin, middle);
		sortVector(middle, end);
		mergeVector(begin, middle, end);
	}
	else
		insertionVector(begin, end);
}

void	PmergeMe::displayVector(std::string str) const{
	std::cout << str;
	for(__SIZE_TYPE__ i = 0; i < _vector.size(); i++)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;
}
