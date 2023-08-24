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
		if (!firstForm.isSigned())
			std::cout << "firstForm not signed.\n";
		else
			std::cout << "firstForm is signed.\n";
		first.signForm(firstForm);
		if (!firstForm.isSigned())
			std::cout << "firstForm not signed.\n";
		else
			std::cout << "firstForm is signed.\n";
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
		return(1);
	}
}
