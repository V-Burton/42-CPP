#include "Fixed.hpp"

const int _nbFractionalBits = NBFRACTIONALBITS;

Fixed::Fixed(): _fixedPoint(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &Fixed){
	std::cout << "Copy constructor called" << std::endl;
	*this = Fixed;
}

Fixed &Fixed::operator=(const Fixed &Fixed){
	std::cout << "Copy assignement operator called" << std::endl;
	this->_fixedPoint = Fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const {
	std::cout << "getRawBits function called" << std::endl;
	return (this->_fixedPoint);
}

void	Fixed::setRawBits(int const raw){
	this->_fixedPoint = raw;
}
