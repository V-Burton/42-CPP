#include "RPN.hpp"

int main(int argc, char **argv){
    if (argc != 2){
        std::cerr << "Proper use : ./RPN \"Inverted Polish mathematical expression\"" << std::endl;
        return (1);
    }

    int sign = 0;
    int operand = 0;
    for (int i = 0; argv[1][i] ; i++){
        if ((argv[1][i] > '9' || argv[1][i] < '0') && argv[1][i] != ' ' && argv[1][i] != '+' && argv[1][i] != '-' && argv[1][i] != '*' && argv[1][i] != '/'){
            std::cerr << "Error" << std::endl;
            return (1);
        }
        if (argv[1][i] == '+' || argv[1][i] == '-' || argv[1][i] == '*' || argv[1][i] == '/')
            sign++;
        if (argv[1][i] < '9' && argv[1][i] > '0')
            operand++;
    }
    if ((operand - sign) != 1){
       std::cerr << "Error2" << std::endl;
        return (1);
    }

    try{
        // std::cout << "je passe ici" <<std::endl;
        RPN test = RPN(argv[1]);
        test.calculate();
    }
    catch(std::exception &e){
        std::cerr << e.what() << std::endl;
    }
    return (0);
}