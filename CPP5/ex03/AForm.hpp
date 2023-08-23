#pragma once

#include <string>
#include <iostream>

class Bureaucrat;

class Form{
	public:
		Form(std::string name, int signGrade, int executeGrade);
		Form(const Form &rhs);
		Form &operator=(const Form &rhs);
		virtual ~Form();

		const std::string	getName() const;
		bool				isSigned() const;
		void				setSigned(bool value);
		int					getSignGrade() const;
		int					getExecuteGrade() const;
		void				beSigned(Bureaucrat rhs);
		virtual void		execute(const Bureaucrat &executor) const = 0;


		class GradeToLowException: public std::exception{
			const char* what() const throw();
		};
		class GradeToHighException: public std::exception{
			const char* what() const throw();
		};
		class FormNotSignedException: public std::exception{
			const char* what() const throw();
		};

	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_executeGrade;
		Form();
};

std::ostream &operator<<(std::ostream &out, Form &rhs);
