#include "Fixed.hpp"

Fixed::Fixed(): _fixedPoint(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &rhs){
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

Fixed &Fixed::operator=(const Fixed &rhs){
	std::cout << "Copy assignement operator called" << std::endl;
	this->_fixedPoint = rhs.getRawBits();
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
