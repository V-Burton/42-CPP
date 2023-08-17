#pragma once

#include <string>
#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Form;

class Bureaucrat{
	public:
		Bureaucrat();
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

		const std::string getName() const;
		int			getGrade() const;
		void		increment();
		void		decrement();
		void		signForm(Form &form) const;

	private:
		const std::string	_name;
		int					_grade;
};

std::ostream &operator<<(std::ostream &out, Bureaucrat &rhs);
