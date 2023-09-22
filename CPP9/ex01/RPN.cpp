#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(std::string input){

	std::istringstream iss(input);
	std::string value;

	while (std::getline(iss, value, ' ')){
		if ()
	}

	
	// int	i = 0;
	// int	checkOperator = 0;
	// int	checkValue = 0;
	// std::stack<int> _bufferValue;
	// std::stack<std::string> _bufferOperator;
	// std::istringstream iss(input);
	// std::string value;

	// while (std::getline(iss, value, ' ')){
	// 	if (std::isdigit(value[0])){
	// 		// if (checkValue != 0 && i > 1)
	// 		// 	throw std::runtime_error("Error: not a good format1 : '" + input + "'");
	// 		_bufferValue.push(static_cast<int>(atoi(value.c_str())));
	// 		checkOperator = 0;
	// 		checkValue++;
	// 	}
	// 	else{
	// 		// if (checkOperator != 0 || value.size() > 1)
	// 		// 	throw std::runtime_error("Error: not a good format2 : '" + input + "'");
	// 		_bufferOperator.push(value);
	// 		checkOperator++;
	// 		checkValue = 0;
	// 	}
	// 	if (_bufferValue.size() == 1 && _bufferOperator.size() == 1)
	// 			throw std::runtime_error("Error: not a good format3 : '" + input + "'");
	// 	i++;
	// }
	
	// while (!_bufferValue.empty()){
	// 	int	buffer = _bufferValue.top();
	// 	_bufferValue.pop();
	// 	_value.push(buffer);
	// }
	// while (!_bufferOperator.empty()){
	// 	std::string	buffer = _bufferOperator.top();
	// 	_bufferOperator.pop();
	// 	_operator.push(buffer);
	// }
}

RPN::RPN(const RPN &rhs){
	*this = rhs;
}

RPN &RPN::operator=(const RPN &rhs){
	if (this != &rhs){
		this->_operator = rhs._operator;
		this->_value = rhs._value;
	}
	return (*this);
}

RPN::~RPN(){}

void	RPN::calculate(){
	int		result = _value.top(); 
	int		buffer = _value.top();
	std::string	operand;
	
	_value.pop();
	while (!_value.empty()){
		operand = _operator.top();
		if (operand == "+")
			result += _value.top();
		else if (operand == "-")
			result -= _value.top();
		else if (operand == "*")
			result *= _value.top();
		else if (operand == "/")
			result /= _value.top();
		_value.pop();
		_operator.pop();
	}
	std::cout << result << std::endl;
}