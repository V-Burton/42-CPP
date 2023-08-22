#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(){

	Bureaucrat first = Bureaucrat("First", 1);
	Bureaucrat fifth = Bureaucrat("Fifth", 5);
	Bureaucrat sixth = Bureaucrat("Sixth", 6);
	Bureaucrat middle = Bureaucrat("Middle", 70);
	Bureaucrat last = Bureaucrat("Last", 150);

	// Form random = Form();
	PresidentialPardonForm pardon = PresidentialPardonForm("victor");
	RobotomyRequestForm robot = RobotomyRequestForm("Guillaume");
	ShrubberyCreationForm shrubbery = ShrubberyCreationForm("Shrubbery");

	std::cout << "---------- Test up and down -----------\n";
	std::cout << first;
	std::cout << fifth;
	std::cout << sixth;
	std::cout << middle;
	std::cout << last;
	middle.increment();
	std::cout << middle;
	middle.decrement();
	std::cout << middle;
	try{
		first.increment();
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
	try{
		last.decrement();
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n---------- Test sign or not -----------\n";
	try {
		first.executeForm(shrubbery);
	}
	catch (std::exception &e){
		std::cout << e.what();
	}

	std::cout << "\n---------- level execute and sign -----------\n";
	try {
		robot.beSigned(last);
	}
	catch (std::exception &e){
		std::cout << e.what();
	}
	middle.signForm(robot);
	try {
		middle.signForm(robot);
	}
	catch (std::exception &e){
		std::cout << e.what();
	}
	try{
		middle.executeForm(robot);
	}
	catch (std::exception &e){
		std::cout << e.what();
	}
	first.executeForm(robot);
	try{
		first.executeForm(shrubbery);
	}
	catch (std::exception &e){
		std::cout << e.what();
	}

	std::cout << "\n---------- Exact level to execute and sign -----------\n";
	fifth.signForm(pardon);
	try{
		sixth.executeForm(pardon);
	}
	catch (std::exception &e){
		std::cout << e.what();
	}
	fifth.executeForm(pardon);
	middle.signForm(shrubbery);
	try{
		middle.executeForm(shrubbery);
	}
	catch (std::exception &e){
		std::cout << e.what();
	}

	return (0);
}
