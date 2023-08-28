#include "ScalarConvert.hpp"

int main(int argc, char **argv){
	ScalarConvert convertor = ScalarConvert();

	if (argc != 2)
		return (1);
	convertor.convert(argv[1]);

	return (0);
}
