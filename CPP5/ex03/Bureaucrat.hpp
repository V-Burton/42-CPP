#pragma once

#include <string>
#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class Form;

class Bureaucrat{
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &rhs);
		Bureaucrat &operator=(const Bureaucrat &rhs);
		~Bureaucrat();

	class GradeToHighException: public std::exception{
		public:
			const char *what() const throw();
	};
	class GradeToLowException: public std::exception{
		public:
			const char *what() const throw();
	};

		std::string getName() const;
		int			getGrade() const;
		void		increment();
		void		decrement();
		void		signForm(Form &form) const;
		void		executeForm(const Form &form);

	private:
		const std::string	_name;
		int					_grade;
		Bureaucrat();
};

std::ostream &operator<<(std::ostream &out, Bureaucrat &rhs);
