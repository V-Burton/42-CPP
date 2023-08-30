#include "Array.hpp"

template <typename T>
Array<T>::Array(): _array(new T[0]), _size(3){}

template <typename T>
Array<T>::Array(unsigned int n): _array(new T[n]), _size(n){}

template <typename T>
Array<T>::Array(const Array &rhs){
    *this = rhs;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &rhs){
    this->_size = rhs._size;
    this->_array = new T[this->_size];
    for (int i = 0; i < this->_size; i++)
        this->_array[i] = rhs._array[i];
}

template <typename T>
Array<T>::~Array(){
    delete[] (this->_array);
}

template<typename T>
T   &Array<T>::operator[](unsigned int n){
    try {
        this->accessGranted(n);
    }
    catch (std::exception &e){
        std::cerr << e.what() << std::endl;
    }
    return (this->_array[n]);
  }

template <typename T>
unsigned int    Array<T>::size() const{
    return (this->_size);
}

template<typename T>
void    Array<T>::accessGranted(unsigned int n) const{
    if (n < this->_size){
    }
    else
        throw Array::OutOfBound();
}

template<typename T>
std::ostream &operator<<(std::ostream &out, const Array<T> &a){
    (void)a;
    out << "test";
    return (out);
}

template<typename T>
const char *Array<T>::OutOfBound::what() const throw(){
    return ("The index ask doesn't exist in the array.");
}