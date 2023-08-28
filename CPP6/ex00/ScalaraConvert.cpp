#include "ScalarConvert.hpp"

ScalarConvert::ScalarConvert(){}

ScalarConvert::ScalarConvert(std::string str): _str(str){}

ScalarConvert::ScalarConvert(const ScalarConvert &rhs): _str(rhs._str){
	*this = rhs;
}

ScalarConvert &ScalarConvert::operator=(const ScalarConvert &rhs){
	if (this == &rhs)
		return (*this);
	this->_c 			= rhs._c;
	this->_i 			= rhs._i;
	this->_f 			= rhs._f;
	this->_d 			= rhs._d;
	this->_impossible	= rhs._impossible;
	this->_type 		= rhs._type;
	return (*this);
}

ScalarConvert::~ScalarConvert(){}

void ScalarConvert::convert(void){
	std::istringstream iss(_str);
	switch (_type) {
		case(CHAR):
			_c = _str[0];
			_i = static_cast<int>(_c);
			_f = static_cast<float>(_c);
			_d = static_cast<double>(_c);
			break ;
		case(INT):
			iss >> _i;
			_c = static_cast<char>(_i);
			_f = static_cast<float>(_i);
			_d = static_cast<double>(_i);
			break ;

		case(FLOAT):
			iss >> _f;
			_c = static_cast<char>(_f);
			_i = static_cast<int>(_f);
			_d = static_cast<double>(_f);
			break ;

		case(DOUBLE):
			iss >> _d;
			_c = static_cast<char>(_d);
			_f = static_cast<float>(_d);
			_i = static_cast<int>(_d);
			break;
		case(STRING):
			break;
		default:
			throw ConvertException();
	}
}

void	ScalarConvert::setType(){
	if (isChar())
		this->_type = CHAR;
	else if (isInt())
		this->_type = INT;
	else if (isDouble())
		this->_type = DOUBLE;
	else if (isFloat())
		this->_type = FLOAT;
	else if (isString())
		this->_type = STRING;
	else
		this->_type = NONE;
}

bool	ScalarConvert::isChar() const{
	if (_str.length() == 1 && std::isalpha(_str[0]) && std::isprint(_str[0]))
		return (true);
	return (false);
}

bool	ScalarConvert::isInt() const{
	for (size_t i = 0; i < _str.length() ; i++)
	{
		if(!isdigit(_str[i]))
			return (false);
	}
	return (true);
}

bool	ScalarConvert::isFloat() const{
	if (_str.find('.') == std::string::npos || _str[_str.length()] != 'f' || _str.find('.') != _str.length() - 2)
		return (false);
	size_t	i = 0;
	int	dot = 0;
	if (_str[0] == '-' || _str[0] == '+')
		i++;
	for (size_t j = i; j < _str.length(); j++){
		if (_str[j] == '.')
			dot++;
		if(!std::isdigit(_str[j]) && dot > 1)
			return (false);
	}
	return (true);
}

bool	ScalarConvert::isDouble() const{
	if (_str.find('.') == std::string::npos || _str.find('.') == 0 || _str[_str.length()] == '.')
		return (false);
	size_t	i = 0;
	int	dot = 0;
	if (_str[0] == '-' || _str[0] == '+')
		i++;
	for (size_t j = i; j < _str.length() - 1; j++){
		if (_str[j] == '.')
			dot++;
		if((!std::isdigit(_str[j]) && _str[j] != '.') || dot > 1)
			return (false);
	}
	return (true);
}

bool	ScalarConvert::isString() const{
	if (_str == "nan" || _str == "nanf" || _str == "-inf" ||
						 _str == "+inf" || _str == "-inff" || _str == "+inff")
		return (true);
	return (false);
}

void	ScalarConvert::printChar() const{
	if (_type == STRING || _type == NONE)
		std::cout << "Impossible" << std::endl;
	else if (!std::isprint(_c))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << _c << "'" << std::endl;
}

void ScalarConvert::printInt() const {
	if (_type == STRING || _type == NONE)
		std::cout << "Impossible" << std::endl;
	else
		std::cout << _i << std::endl;
}

void ScalarConvert::printFloat() const{
	if (_str == "nan")
		std::cout << "nanf" << std::endl;
	else if (_str == "+inf")
		std::cout << "+inff" << std::endl;\
	else if (_str == "-inf")
		std::cout << "-inff" << std::endl;
	else if (_type == STRING)
		std::cout << _str << std::endl;
	else{
		std::cout << _f;
		if (_type == INT || _type == CHAR)
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
}

void ScalarConvert::printDouble() const{
	if (_str == "nanf")
		std::cout << "nan" << std::endl;
	else if (_str == "+inff")
		std::cout << "+inf" << std::endl;\
	else if (_str == "-inff")
		std::cout << "-inf" << std::endl;
	else if (_type == STRING)
		std::cout << _str << std::endl;
	else{
		std::cout << _d;
		if (_type == INT || _type == CHAR)
			std::cout << ".0";
		std::cout << std::endl;
	}
}

const char *ScalarConvert::ConvertException::what() const throw(){
	return ("Unknown type\n");
}

std::ostream &operator<<(std::ostream &out, const ScalarConvert &rhs){
	out << "char: ";
	rhs.printChar();
	out << "int: ";
	rhs.printInt();
	out << "float: ";
	rhs.printFloat();
	out << "double: ";
	rhs.printDouble();
	return (out);
}
