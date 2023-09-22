#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(std::string input){

	std::istringstream iss(input);
	std::string value;
	int operand1;
	int	operand2;

	while (std::getline(iss, value, ' ')){
		if (value == "+" || value == "-" || value == "*" || value == "/"){
			operand2 = _value.top();
			_value.pop();
			operand1 = _value.top();
			_value.pop();
			if(value == "+")
				_value.push(operand1 + operand2);
			else if(value == "-")
				_value.push(operand1 - operand2);
			else if(value == "*")
				_value.push(operand1 * operand2);
			else if (value == "/" && operand2 != 0)
				_value.push(operand1 / operand2);
			else
				throw std::runtime_error("Division by zero impossible.");
		}
		else
			_value.push(static_cast<int>(atoi(value.c_str())));
	}
	std::cout << _value.top() << std::endl;
}

RPN::RPN(const RPN &rhs){
	*this = rhs;
}

RPN &RPN::operator=(const RPN &rhs){
	if (this != &rhs)
		this->_value = rhs._value;
	return (*this);
}

RPN::~RPN(){}
