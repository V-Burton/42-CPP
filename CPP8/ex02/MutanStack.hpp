#pragma once

#include <iostream>

template<typename T>
class MutanStack: public std::stack<T>{
	public:
		MutanStack(): std::stack<T>(){};
		MutanStack(const MutanStack &rhs): std::stack<T>(rhs){};
		MutanStack &operator=(const MutanStack &rhs){
			if (*this == rhs)
				return (*this)
			*this = rhs;
			return (*this;)
		};
		~MutanStack(){};

};
