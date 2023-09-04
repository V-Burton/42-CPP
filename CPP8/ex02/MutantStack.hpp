#pragma once

#include <iostream>
#include <stack>
#include <algorithm>

template<typename T> class MutantStack: public std::stack<T>{
	public:
		MutantStack(): std::stack<T>(){};
		MutantStack(const MutantStack &rhs): std::stack<T>(rhs){
			this->c = rhs.c;
		};
		MutantStack &operator=(const MutantStack &rhs){
			if (*this == rhs)
				return (*this);
			*this->c = rhs.c;
			return (*this);
		};
		~MutantStack(){};

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin(){ return (this->c.begin());};
		iterator end(){ return (this->c.end());};

};
