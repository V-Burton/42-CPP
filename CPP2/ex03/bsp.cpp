#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point){
    
    Fixed alpha = (a.getX() - point.getX())*(b.getY() - point.getY()) - (a.getY() - point.getY()) * (b.getX() - point.getX());
    Fixed beta = (b.getX() - point.getX())*(c.getY() - point.getY()) - (b.getY() - point.getY()) * (c.getX() - point.getX());
    Fixed gamma = (c.getX() - point.getX())*(a.getY() - point.getY()) - (c.getY() - point.getY()) * (a.getX() - point.getX());
    if ((alpha.getRawBits() > 0 && beta.getRawBits() > 0 && gamma.getRawBits() > 0) || (alpha.getRawBits() < 0 && beta.getRawBits() < 0 && gamma.getRawBits() < 0) )
        return (true);
    return (false);
}
