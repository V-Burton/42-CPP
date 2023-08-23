#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): Form("ShrubberyCreationForm", 145, 137), _target("default"){
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("ShrubberyCreationForm", 145, 137), _target(target){
}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs): Form(rhs){
	*this = rhs;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs){
	if (this == &rhs)
		return (*this);
	this->_target = rhs._target;
	this->setSigned(rhs.isSigned());
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const{
	if (!this->isSigned())
		throw FormNotSignedException();
	else if (executor.getGrade() > this->getExecuteGrade())
		throw GradeToLowException();
	std::ofstream outfile(this->_target.c_str());
	if (!outfile.is_open()){
		std::cerr << "Error opening the file!" << std::endl;
		return ;
	}
	outfile <<
		"	oxoxoo    ooxoo\n"
		"  ooxoxo oo  oxoxooo\n"
		" oooo xxoxoo ooo ooox\n"
		" oxo o oxoxo  xoxxoxo\n"
		"  oxo xooxoooo o ooo\n"
		"    oooooo   /o/o\n"
		"         |   / /\n"
		"         |   /\n"
		"         |  |\n"
		"         | D|\n"
		"         |  |\n"
		"         |  |\n"
		"  ______/____ ____\n";

	outfile.close();
	std::cout << "Shrubbery form has been execute corectly.\n";
}
