#include "iter.hpp"

void    square(int &a){
    a *= a;
}

void    display(std::string &str){
    std::cout << str << std::endl;
}

struct Data {
    int         i;
    double      d;
    std::string name;
};

void    demonstration(Data  &d){
    std::cout << "Addition of i and d from Data " << d.name << " is " << d.i + d.d << std::endl;
}

int main(){
    int   array[5];

    for (int i = 0; i < 5; i++)
    {
        array[i] = i;
        std::cout << array[i] << ", ";
    }
    std::cout << std::endl;
    ::iter(array, 5, square);
    for (int i = 0; i < 5; i++)
        std::cout << array[i]<< ", ";
    std::cout << std::endl ;

    /*--------------------------------------*/

    std::string arrayB[] = {"Hello", "World"};
    ::iter(arrayB, 2, display);

    /*--------------------------------------*/

    Data    A, B, C;
    A.name = "A";
    A.i = 40;
    A.d = 2.0;
    B.name = "B";
    B.i = 38;
    B.d = 2.0; 
    C.name = "C";
    C.i = 36;
    C.d = 2.0; 
    Data    arrayD[3] = {A, B, C};
    ::iter(arrayD, 3, demonstration);

    return (0);
}
