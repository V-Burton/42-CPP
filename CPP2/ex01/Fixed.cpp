#include <Fixed.hpp>
#include <cmath>

Fixed::Fixed(): _fixedPoint(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int raw){
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPoint = (int)(raw * (1 << _nbFractionalBits));
}

Fixed::Fixed(const float raw){
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPoint = (int)(roundf(raw * (1 << _nbFractionalBits)));
}

Fixed::Fixed(const Fixed &src){
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &rhs){
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPoint = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

std::ostream & operator<<(std::ostream & o, const Fixed & rhs){
	o << rhs.toFloat();
	return (o);
}

int	Fixed::getRawBits(void) const{
	return(this->_fixedPoint);
}

void Fixed::setRawBits(int const raw){
	this->_fixedPoint = raw;
}

float	Fixed::toFloat(void) const{
	return ((float)this->getRawBits() / (float)(1 << _nbFractionalBits));
}

int	Fixed::toInt(void) const{
	return ((int)this->getRawBits() / (int)(1 << _nbFractionalBits));
}
