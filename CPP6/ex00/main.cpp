#include "ScalarConvert.hpp"

int main(int argc, char **argv){

	if (argc != 2)
		return (1);
	ScalarConvert convertor = ScalarConvert(argv[1]);
	
	convertor.setType();
	try{
		convertor.convert();
		std::cout << convertor;
	}
	catch (std::exception &e){
		std::cerr << e.what();
	}

	return (0);
}
