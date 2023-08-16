#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){}

Bureaucrat::Bureaucrat(std::string name, int grade):_name(name){
	if (grade > 150)
		throw GradeToLowException();
	else if (grade <= 0)
		throw GradeToHighException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs){
	*this = rhs;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs){
	this->_grade = rhs._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(){}

const std::string Bureaucrat::getName() const{
	return (this->_name);
}

int	Bureaucrat::getGrade() const{
	return (this->_grade);
}

void	Bureaucrat::increment(){
	if (this->_grade == 1)
		throw GradeToHighException();
	this->_grade--;
}

void	Bureaucrat::decrement(){
	if (this->_grade == 150)
		throw GradeToLowException();
	this->_grade++;
}

const char *Bureaucrat::GradeToHighException::what() const throw(){
	return ("Bureaucrat's grade is to high!");
}

const char *Bureaucrat::GradeToLowException::what() const throw(){
	return ("Bureaucrat's grade is to low!");
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &rhs){
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".\n";
	return (out);
}

