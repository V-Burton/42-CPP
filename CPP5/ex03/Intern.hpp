#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Form;

class Intern {
    public:
        Intern();
        Intern(const Intern &rhs);
        Intern &operator=(const Intern &rhs);
        ~Intern();

        Form    *makeForm(std::string formName, std::string target);
};