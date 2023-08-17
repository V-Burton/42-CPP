#include "Bureaucrat.hpp"

int main(){
	try{
		Bureaucrat first = Bureaucrat("Jean", 1);
		std::cout << first;
		// Bureaucrat error = Bureaucrat("fuck", 170);
		// std::cout << error.getName() << ", grade is : " << error.getGrade() << ".\n";
		Bureaucrat last = Bureaucrat("Denis", 150);
	std::cout << last ;		// last.decrement();
		Form firstForm = Form("first", 10, 10);
		std::cout << firstForm << std::endl;
		// firstForm.beSigned(last);
		// std::cout << firstForm << std::endl;
		first.signForm(firstForm);
		std::cout << firstForm << std::endl;
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
		return(1);
	}
	return (0);
}
