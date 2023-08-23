#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name("Default"), _signed(false), _signGrade(150), _executeGrade(150){}

Form::Form(std::string name, int signGrade, int executeGrade):_name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade){
	if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeToLowException();
	else if (signGrade <= 0 || executeGrade <= 0)
		throw Form::GradeToHighException();
}

Form::Form(const Form &rhs): _name(rhs._name), _signGrade(rhs._signGrade), _executeGrade(rhs._executeGrade){
	*this = rhs;
}

Form &Form::operator=(const Form &rhs){
	if (this == &rhs)
		return (*this);
	this->_signed = rhs._signed;
	return (*this);
}

Form::~Form(){}

const std::string Form::getName() const{
	return (this->_name);
}

bool	Form::isSigned() const{
	return (this->_signed);
}

int	Form::getSignGrade() const{
	return (this->_signGrade);
}

int	Form::getExecuteGrade() const{
	return (this->_executeGrade);
}


void	Form::beSigned(Bureaucrat rhs){
	if (rhs.getGrade() <= this->_signGrade && !this->_signed)
		this->_signed = true;
	else
		throw Bureaucrat::GradeToLowException();
}

const char *Form::GradeToHighException::what() const throw(){
	return ("Form's grade is to high!");
}

const char *Form::GradeToLowException::what() const throw(){
	return ("Form's grade is to Low!");
}

std::ostream &operator<<(std::ostream &out, Form &rhs){
	std::string signedResult;
	if (rhs.isSigned() == true)
		signedResult = "signed";
	else
		signedResult = "not signed";
	out << "Form's name: " << rhs.getName() << " signable by grade " << rhs.getSignGrade() << " and executable by grade " << rhs.getSignGrade() << " is " << signedResult << ".";
	return (out);
}
