#include "Bureaucrat.hpp"

int main(){
	try{
		Bureaucrat first = Bureaucrat("Jean", 1);
		std::cout << first << std::endl;
		Bureaucrat last = Bureaucrat("Denis", 150);
		std::cout << last << std::endl;
		first.decrement();
		std::cout << first << std::endl;
		// last.decrement();
		// Bureaucrat error = Bureaucrat("fuck", 170);
		// std::cout << error.getName() << ", grade is : " << error.getGrade() << ".\n";
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
		return(1);
	}
	return (0);
}
