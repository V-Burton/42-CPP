#include "Point.hpp"

Point::Point():_x(0), _y(0){}

Point::Point(const float &x, const float &y):_x(Fixed(x)), _y(Fixed(y)){}

Point::Point(const Point &rhs):_x(rhs._x), _y(rhs._y){}

Point::~Point(){}

Point &Point::operator=(const Point &rhs){
    (Fixed)this->_x = rhs.getX();
    (Fixed)this->_y = rhs.getY();
    return (*this);
}

Fixed   Point::getX() const{
    return (this->_x);
}

Fixed   Point::getY() const{
    return (this->_y);
}