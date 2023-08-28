#include "Base.hpp"

#include <cstdlib>
#include <iostream>

Base *generate(void){
    int result = rand() % 3;
    switch (result){
        case (0):
            return (new A());
        case (1):
            return (new B());
        case (2):
            return (new C());
        default:
            return (NULL);
    }
}

void    identify(Base *p){
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "The type of the argument given is : 'A'." << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "The type of the argument given is : 'B'." << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "The type of the argument given is : 'C'." << std::endl;
    else
        std::cout << "The type of the argument given is unknown." << std::endl;
}

void    identify(Base &p){
    Base result;

    try {
        result = dynamic_cast<A&>(p);
        std::cout << "The type of the argument given is : 'A'." << std::endl;
        return ;
    }
    catch(...){
    }
    try {
        result = dynamic_cast<B&>(p);
        std::cout << "The type of the argument given is : 'B'." << std::endl;
        return ;
    }
    catch(...){ 
    }
    try {
        result = dynamic_cast<C&>(p);
        std::cout << "The type of the argument given is : 'C'." << std::endl;
        return ;
    }
    catch(...){
    }
    std::cout << "The type of the argument given is unknown." << std::endl;

}


int main(){
    srand(time(NULL));
    Base    *generated = generate();
    Base    *fail = new Fail();

    try{
        identify(*generated);
        identify(generated);
        identify(*fail);
        identify(fail);
    }
    catch(std::bad_alloc &e){
        std::cout << "The type of the argument given is unknown." << std::endl;
    }

}