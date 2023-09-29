#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(std::string input){

	std::istringstream iss(input);
	std::string value;
	int i = 0;
	int operand1;
	int	operand2;

	while (std::getline(iss, value, ' ')){
		if (value == "+" || value == "-" || value == "*" || value == "/"){
			if (_value.size() < 2)
				throw std::runtime_error("Wrong Format.");
			operand2 = _value.top();
			_value.pop();
			operand1 = _value.top();
			_value.pop();
			if (operand1 > std::numeric_limits<int>::max() || operand1 < std::numeric_limits<int>::min() || \
				 operand2 > std::numeric_limits<int>::max() || operand2 < std::numeric_limits<int>::min())
				throw std::runtime_error("result is bigger than an 'int'.");
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
		else{
			long result = static_cast<long>(atof(value.c_str()));
			if (result)
				_value.push(result);
		}
		i++;
	}
	std::cout << std::setprecision(7) << _value.top() << std::endl;
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
