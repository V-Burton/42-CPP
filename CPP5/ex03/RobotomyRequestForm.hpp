#pragma once

#include "AForm.hpp"

#define MAX_RAND 2

class RobotomyRequestForm: public Form {
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &rhs);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
		~RobotomyRequestForm();

		void	execute(const Bureaucrat &executor) const;

	private:
		std::string _target;
		RobotomyRequestForm();
};
