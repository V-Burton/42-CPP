#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	{
		Span sp1 = Span(5);
		sp1.addNumber(6);
		sp1.addNumber(3);
		sp1.addNumber(17);
		sp1.addNumber(9);
		sp1.addNumber(11);
		try{
			sp1.addNumber(19);
		}
		catch(std::exception const &e){
			std::cerr << e.what();
		}
	}
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span sp2 = Span(10200);
	try{
	sp2.addMultipleNumber(0, 10200);
	}
	catch(std::exception &e){
		std::cerr << e.what();
	}
	try{
		sp2.addNumber(0);
		sp2.addNumber(19);
	}
	catch(std::exception &e){
		std::cerr << e.what();
	}
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
	return 0;
}
