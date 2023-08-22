#include <cstdlib>
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): Form("RobotomyRequestForm", 72, 45){
	this->_target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("RobotomyRequestForm", 72, 45){
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs): Form(rhs){
	*this = rhs;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs){
	this->_target = rhs._target;
	this->setSigned(rhs.isSigned());
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const{
	if (!this->isSigned())
		throw FormNotSignedException();
	else if (executor.getGrade() > this->getExecuteGrade())
		throw GradeToLowException();
	std::cout << "zzzzZZZZZZZZZZzzzzZZZZZzzZZZzZZZZZZZzzZZZZZzz *drilling noises*.\n";
	int	success = rand() % 100;
	if (success < 50)
		std::cout << this->_target << " has been successfully robotomized.\n";
	else
		std::cout << "The robotomy failed on " << this->_target << ".\n";
}
