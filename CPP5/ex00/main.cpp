#include "Bureaucrat.hpp"

int main(){
	try{
		Bureaucrat first = Bureaucrat("Jean", 1);
		std::cout << first.getName() << ", grade is : " << first.getGrade() << ".\n";
		Bureaucrat last = Bureaucrat("Denis", 150);
		std::cout << last.getName() << ", grade is : " << last.getGrade() << ".\n";
		last.decrement();
		Bureaucrat error = Bureaucrat("fuck", 170);
		std::cout << error.getName() << ", grade is : " << error.getGrade() << ".\n";
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
		return(1);
	}
	return (0);
}
