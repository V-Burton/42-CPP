#include "ScalarConvert.hpp"

ScalarConvert::ScalarConvert(){}

ScalarConvert::ScalarConvert(const ScalarConvert &rhs){
	*this = rhs;
}

ScalarConvert &ScalarConvert::operator=(const ScalarConvert &rhs){
	if (this == &rhs)
		return (*this);
	*this = rhs;
	return (*this);
}

ScalarConvert::~ScalarConvert(){}

void ScalarConvert::convert(const std::string str){

}

bool	isInt(const std::string &str){
	int	j = 0;

	if (str[0] == '-' || str[0] == '+')
		j++;
	for (int i = j; i < str.length(); i++){
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

bool	isDouble(const std::string &str){
	int	j = 0;

	if (str[0] == '-' || str[0] == '+')
		j++;
	
}
