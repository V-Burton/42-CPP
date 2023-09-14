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

// void	PmergeMe::insertion(int begin, int end){
// 	for (int i = 0; i < end - 1; i++){
// 		int buffer = _vector[i + 1];
// 		int j = i + 1;
// 		while (j > begin && buffer < _vector[j - 1]){
// 			_vector[j] = _vector[j - 1];
// 			j--;
// 		}
// 		_vector[j] = buffer;
// 	}
// }

// void	PmergeMe::merge(int begin, int middle, int end){
// 	int	iRight = 0, iLeft = 0, first = middle - begin + 1, second = end - middle;
// 	std::vector<int> vectorLeft(_vector.begin() + begin, _vector.begin() + middle + 1 );
// 	std::vector<int> vectorRight(_vector.begin() + middle + 1, _vector.begin() + end + 1);
// 	for (int i = begin; i < end; i++){
// 		if (iRight == second){
// 			_vector[i] = vectorLeft[iLeft];
// 			iLeft++;
// 		}
// 		else if(iLeft == first){
// 			_vector[i] = vectorRight[iRight];
// 			iRight++;
// 		}
// 		else if (vectorRight[iRight] > vectorLeft[iLeft]){
// 			_vector[i] = vectorLeft[iLeft];
// 			iLeft++;
// 		}
// 		else{
// 			_vector[i] = vectorRight[iRight];
// 			iRight++;
// 		}
// 	}
// }

// void	PmergeMe::sort(int begin, int end){
// 	int	middle = (begin + end) / 2;
// 	if (end - begin > INSERTION){
// 		sort(begin, middle + 1);
// 		sort(middle + 1, end);
// 		merge(begin, middle, end);
// 	}
// 	else
// 		insertion(begin, end);
// }

// void	PmergeMe::display() const{
// 	std::cout << "After:	";
// 	for(__SIZE_TYPE__ i = 0; i < _vector.size(); i++)
// 		std::cout << _vector[i] << " ";
// 	std::cout << std::endl;
// }
std::vector<int>	&PmergeMe::getVector(){
	return (this->_vector);
}

std::list<int>	&PmergeMe::getList(){
	return (this->_list);
}

template<typename Container>
void	PmergeMe::display(Container &container){
	for(typename Container::iterator i = container.begin(); i != container.end(); i++){
		std::cout << *i << " ";
	}
	std::cout << std::endl;
}

template<typename Container>
void	PmergeMe::insertion(Container &container, typename Container::iterator begin, typename Container::iterator end){
	for(typename Container::iterator i = begin; i != end; i++){
		typename Container::value_type buffer = *(std::next(i, 1));
		std::iterator j = std::next(i, 1);
		while(j > begin && buffer < *(std::prev(j, 1))){
			*j = *(std::prev(j, 1));
			j--;
		}
		*j = buffer;
	}
}

template<typename Container>
void	PmergeMe::merge(Container &container, typename Container::iterator begin, typename Container::iterator middle, typename Container::iterator end){
	Container containerLeft(begin, std::next(middle, 1));
	Container containerRight(std::next(middle, 1), std::next(end, 1));
	typename Container::iterator iL = containerLeft.begin();
	typename Container::iterator iR = containerRight.begin();

	for(typename Container::iterator i = begin; i != std::next(end, 1); i++){
		if (iR == containerRight.end()){
			*i = *iL;
			iL++;
		}
		else if (iL == containerLeft.end()){
			*i = *iR;
			iR++;
		}
		else if (*iR > *iL){
			*i = *iL;
			iL++;
		}
		else{
			*i = *iR;
			iR++;
		}
	}
}

template<typename Container>
void	PmergeMe::sort(Container& container, typename Container::iterator begin, typename Container::iterator end){
	typename Container::iterator middle = std::next(begin, std::distance(begin, end) / 2);
	if (std::distance(begin, end) > INSERTION){
		sort(begin, middle + 1);
		sort(middle + 1, end);
		merge(begin, middle, end);
	}
	else {
		insertion(begin, end);
	}
}
