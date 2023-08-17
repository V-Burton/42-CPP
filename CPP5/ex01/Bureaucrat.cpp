#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Default"), _grade(150){}

Bureaucrat::Bureaucrat(std::string name, int grade):_name(name){
	if (grade > 150)
		throw GradeToLowException();
	else if (grade <= 0)
		throw GradeToHighException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs): _name(rhs._name){
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

void	Bureaucrat::signForm(Form &form) const{
	bool	isSigned = form.isSigned();

	try {
		form.beSigned(*this);
		if (isSigned == true)
			std::cout << this->_name << " couldn't sign " << form.getName() << " because form is already sign." << std::endl;
		else
			std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e){
		std::cerr << e.what() << " Required grade is " << form.getSignGrade() << " and " << this->_name << " is grade " << this->_grade << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &rhs){
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".\n";
	return (out);
}

