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

        std::string getName() const;
        void    setName(std::string name);

        bool operator==(const Point &rhs) const;
    private:
        std::string _name;
        const Fixed _x;
        const Fixed _y;
};