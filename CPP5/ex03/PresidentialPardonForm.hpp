#pragma once

#include "AForm.hpp"

class PresidentialPardonForm: public Form{
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &rhs);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
		~PresidentialPardonForm();

		void	execute(const Bureaucrat &executor) const;

	private:
		std::string _target;
		PresidentialPardonForm();
};
