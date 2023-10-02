#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(std::string input){

	std::istringstream iss(input);
	std::string value;
	float 	operand1;
	float	operand2;
	float	checkerValue;
	int		i = 0;

	while (input[i]){
		if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/'){
			if (_value.size() < 2)
				throw std::runtime_error("Problem format: wrong order in operand and operator");
			operand2 = _value.top();
			_value.pop();
			operand1 = _value.top();
			_value.pop();
			if(input[i] == '+')
				checkerValue = operand1 + operand2;
			else if(input[i] == '-')
				checkerValue = operand1 - operand2;
			else if(input[i] == '*')
				checkerValue = operand1 * operand2;
			else if (input[i] == '/' && operand2 != 0)
				checkerValue = operand1 / operand2;
			else
				throw std::runtime_error("Division by zero impossible.");
			if (checkerValue <= 2147483647 && checkerValue >= -2147483648)
				_value.push(checkerValue);
			else
				throw std::runtime_error("Error: overflow: result bigger than an int.");
		}
		else if (!std::isspace(static_cast<unsigned char>(input[i])))
			_value.push(static_cast<float>(input[i]) - 48);
		i++;
	}
	if (_value.size() > 1)
		throw std::runtime_error("Problem format");
	std::cout << std::setprecision(10) << _value.top() << std::endl;
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
