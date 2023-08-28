#include "Serializer.hpp"

int main(){
    Data base;

    base.i = 42;
    base.f = 42.5f;
    base.d = 42.5;

    uintptr_t   uReceiver;
    Data        *dReceiver;

    dReceiver = &base;
    uReceiver = Serializer::serialize(dReceiver);

    std::cout << "base      : " << &dReceiver << "\nuReceiver : " << &dReceiver << "\ndReceiver : " << &dReceiver << std::endl;
    std::cout << "i = " << dReceiver->i << " | f = " << dReceiver->f << " | d = " << dReceiver->d << std::endl;
    dReceiver = Serializer::deserialize(uReceiver);

    std::cout << "base      : " << &dReceiver << "\nuReceiver : " << &uReceiver << "\ndReceiver : " << &dReceiver << std::endl;
    std::cout << "i = " << dReceiver->i << " | f = " << dReceiver->f << " | d = " << dReceiver->d << std::endl;

    double result = dReceiver->d + dReceiver->i;
    std::cout << result << std::endl;
}