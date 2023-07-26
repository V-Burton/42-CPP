#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void) {
    Point A = Point(0, 0);
    Point B = Point(3, 0);
    Point C = Point(3, 3);
    Point P = Point(0, 0);
    P.setName("P");
    Point P1 = Point(1, 1);
    P1.setName("P1");
    Point P2 = Point(1, 1.5);
    P2.setName("P2");
    Point P3 = Point(1, 0.5);
    P3.setName("P3");

    std::cout << "Triangle ABC has coordinate: A[" << A.getX() << "; " << A.getY() << "]; B[" << B.getX() << "; " << B.getY() << "]; C[" << C.getX() << "; " << C.getY() << "];" << std::endl;
    if(bsp(A, B, C, P))
        std::cout << P.getName() << "[" << P.getX() << "; " << P.getY() << "] is inside the triangle ABC." << std::endl;
    else
        std::cout << P.getName() << "[" << P.getX() << "; " << P.getY() << "] isn't inside the triangle ABC." << std::endl;
    if(bsp(A, B, C, P1))
        std::cout << P1.getName() << "[" << P1.getX() << "; " << P1.getY() << "] is inside the triangle ABC." << std::endl;
    else
        std::cout << P1.getName() << "[" << P1.getX() << "; " << P1.getY() << "] isn't inside the triangle ABC." << std::endl;
    if(bsp(A, B, C, P2))
        std::cout << P2.getName() << "[" << P2.getX() << "; " << P2.getY() << "] is inside the triangle ABC." << std::endl;
    else
        std::cout << P2.getName() << "[" << P2.getX() << "; " << P2.getY() << "] isn't inside the triangle ABC." << std::endl;
    if(bsp(A, B, C, P3))
        std::cout << P3.getName() << "[" << P3.getX() << "; " << P3.getY() << "] is inside the triangle ABC." << std::endl;
    else
        std::cout << P3.getName() << "[" << P3.getX() << "; " << P3.getY() << "] isn't inside the triangle ABC." << std::endl;
    return (0);
}