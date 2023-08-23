#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern &rhs){
    *this = rhs;
}

Intern &Intern::operator=(const Intern &rhs){
    (void) rhs;
    return (*this);
}

Intern::~Intern(){}

Form *Intern::makeForm(std::string formName, std::string target){

    int i = 0;

    std::string    forms[3] = {"shrubbery request", "pardon request", "robotomy request"};
    while (i < 3){
        if (formName == forms[i])
            break ;
        i++;
    }
    switch (i){
        case 0:
            return (new ShrubberyCreationForm(target));
        case 1:
            return (new PresidentialPardonForm(target));
        case 2:
            return (new RobotomyRequestForm(target));
        default:
            std::cout << "The form you're trying to creat doesn't exist." << std::endl;
            return (NULL);
    }
}