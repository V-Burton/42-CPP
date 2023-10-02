#include "RPN.hpp"

int main(int argc, char **argv){
    if (argc != 2){
        std::cerr << "Proper use : ./RPN \"Inverted Polish mathematical expression\"" << std::endl;
        return (1);
    }

    int sign = 0;
    int operand = 0;
    for (int i = 0; argv[1][i] ; i++){
		if(i % 2 == ' '){
			std::cerr << "Error: Wrong format." << std::endl;
			return (1);
		}
        if ((argv[1][i] > '9' || argv[1][i] < '0') && !std::isspace(static_cast<unsigned char>(argv[1][i])) && argv[1][i] != '+' && argv[1][i] != '-' && argv[1][i] != '*' && argv[1][i] != '/'){
            std::cerr << "Error: wrong characteres in input" << std::endl;
            return (1);
        }
        if ((argv[1][i] == '+' || argv[1][i] == '-' || argv[1][i] == '*' || argv[1][i] == '/') && (std::isspace(static_cast<unsigned char>(argv[1][i + 1])) || argv[1][i + 1] == '\0' || argv[1][i] == '+' || argv[1][i] == '-' || argv[1][i] == '*' || argv[1][i] == '/' ))
            sign++;
        if (argv[1][i] <= '9' && argv[1][i] >= '0')
            operand++;
    }
    if ((operand - sign) != 1){
       std::cerr << "Error: Problem format: operand = " << operand << " and operator = " << sign << "." << std::endl;
        return (1);
    }
    try{
        RPN test = RPN(argv[1]);
    }
    catch(std::runtime_error &e){
        std::cerr << e.what() << std::endl;
    }
    return (0);
}
