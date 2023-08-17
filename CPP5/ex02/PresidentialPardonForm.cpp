#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form("PresidentialPardonForm", 25, 5){
	this->_target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs): Form(rhs){
	*this = rhs;
}

PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs){
	this->_target = rhs._target;
	this->setSigned(rhs.isSigned());
	return (*this);
}

PresidentialPArdonForm::~PresidentialPardonForm(){}

void	PresidentialPardonForm::execute(const Bureaucrat &executor){
	if (!this->isSigned())
		throw FormNotSignException();
	else if (executor.getGrade() > this->executeGrade())
		throw GradeToLowException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox.\n";
}


