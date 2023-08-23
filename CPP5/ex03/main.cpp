#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(){

	Bureaucrat first = Bureaucrat("First", 1);
	Bureaucrat fifth = Bureaucrat("Fifth", 5);
	Bureaucrat sixth = Bureaucrat("Sixth", 6);
	Bureaucrat middle = Bureaucrat("Middle", 70);
	Bureaucrat last = Bureaucrat("Last", 150);

	PresidentialPardonForm pardon = PresidentialPardonForm("victor");
	RobotomyRequestForm robot = RobotomyRequestForm("Guillaume");
	ShrubberyCreationForm shrubbery = ShrubberyCreationForm("Shrubbery");

	std::cout << "---------- Decalration of Bureaucrats -----------\n";
	std::cout << first;
	std::cout << middle;
	std::cout << last;

	std::cout << "---------- Creation of forms -----------\n";

	Intern someRandomIntern;
	Form* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	try{
		rrf->beSigned(last);
	}
	catch (std::exception &e){
		std::cerr << e.what();
	}
	first.signForm(*rrf);
	try{
		rrf->execute(middle);
	}
	catch (std::exception &e){
		std::cerr << e.what();
	}
	first.executeForm(*rrf);
	delete (rrf);
	return (0);
}
