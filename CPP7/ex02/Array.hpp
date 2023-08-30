#pragma once

#include <iostream>

template <typename T>
class Array{
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &rhs);
        Array &operator=(const Array &rhs);
        ~Array();

        T   &operator[](unsigned int n);

        unsigned int    size() const;
        void            accessGranted(unsigned int n) const;   

        class OutOfBound: public std::exception{
            const char *what() const throw();
        };

    private:
        T               *_array;
        unsigned int    _size;
};

template<typename T>
std::ostream &operator<<(std::ostream &out, const Array<T> &a);

#include "Array.tpp"