#pragma once
#include "Fixed.hpp"

class Point{

    public:
        Point();
        Point(const float &x, const float &y);
        Point(const Point &rhs);
        ~Point();

        Point &operator=(const Point &rhs);

        Fixed getX() const;
        Fixed getY() const;
    private:
        const Fixed _x;
        const Fixed _y;
};

std::ostream    &operator<<(std::ostream &out, const Point &point){
    out << "[ " << point.getX() << ";" << point.getY() << " ]";
    return (out);
}