#pragma once

#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include <limits>
#include <sstream>

enum	e_type{
	NONE,
	INT,
	DOUBLE,
	FLOAT,
	CHAR,
	STRING,
};
 
class ScalarConvert{
	public:
		ScalarConvert(std::string str);
		ScalarConvert(const ScalarConvert &rhs);
		ScalarConvert &operator=(const ScalarConvert &rhs);
		~ScalarConvert();

		void convert(void);

		class ConvertException: public std::exception {
			const char *what() const throw();
		};

		void	printChar() const;
		void	printInt() const;
		void	printFloat() const;
		void	printDouble() const;
		void	setType();

	private:

		bool	isChar() const;
		bool	isInt() const;
		bool	isFloat() const;
		bool	isDouble() const;
		bool	isString() const;

		void	setChar();
		void	setInt();
		void	setFloat();
		void	setDouble();

		bool		_impossible;
		e_type		_type;
		std::string	_str;
		char		_c;
		int			_i;
		float		_f;
		double		_d;
		
		ScalarConvert();
};

std::ostream &operator<<(std::ostream &out, const ScalarConvert &rhs);