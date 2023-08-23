#pragma once

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat{
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &rhs);
		Bureaucrat &operator=(const Bureaucrat &rhs);
		~Bureaucrat();

	class GradeToHighException: public std::exception{
		const char *what() const throw();
	};
	class GradeToLowException: public std::exception{
		const char *what() const throw();
	};

		std::string getName() const;
		int			getGrade() const;
		void		increment();
		void		decrement();

	private:
		const std::string	_name;
		int					_grade;
		Bureaucrat();
};

std::ostream &operator<<(std::ostream &out, Bureaucrat &rhs);
