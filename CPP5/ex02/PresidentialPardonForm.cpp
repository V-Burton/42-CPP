#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form("PresidentialPardonForm", 25, 5){
	this->_target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs): Form(rhs){
	*this = rhs;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs){
	this->_target = rhs._target;
	this->setSigned(rhs.isSigned());
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const{
	if (!this->isSigned())
		throw FormNotSignedException();
	else if (executor.getGrade() > this->getExecuteGrade())
		throw GradeToLowException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox.\n";
}


