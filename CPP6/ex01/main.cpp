#include "Serializer.hpp"

int main(){
    Data base;

    base.i = 42;
    base.c = 'C';
    base.d = 42.5;

    uintptr_t   uReceiver;
    Data        *dReceiver;

    dReceiver = &base;
    uReceiver = Serializer::serialize(dReceiver);

    std::cout << "base      : " << &dReceiver << "\nuReceiver : " << &dReceiver << "\ndReceiver : " << &dReceiver << std::endl;
    std::cout << "i = " << dReceiver->i << " | c = " << dReceiver->c << " | d = " << dReceiver->d << std::endl;
    dReceiver = Serializer::deserialize(uReceiver);

    std::cout << "base      : " << &dReceiver << "\nuReceiver : " << &uReceiver << "\ndReceiver : " << &dReceiver << std::endl;
    std::cout << "i = " << dReceiver->i << " | c = " << dReceiver->c << " | d = " << dReceiver->d << std::endl;

    double result = dReceiver->d + dReceiver->i;
    std::cout << result << std::endl;
}