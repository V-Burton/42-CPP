#include "Array.hpp"

struct Data {
    int         i;
    double      d;
    std::string name;
};

int main(){
    Array<int> a;
    Array<double> b(10);
    Array<std::string> s(5);
    Array<Data> d(5);
    
    std::cout << "\n" << a.size() << std::endl;

    a[0] = 2;
    std::cout << a[0] << std::endl;
    d[0].i = 5;
    d[0].i = 42.0;
    d[0].name = "Victor";
    std::cout << d[0].i << std::endl;
    std::cout << d[0].name << std::endl;

}