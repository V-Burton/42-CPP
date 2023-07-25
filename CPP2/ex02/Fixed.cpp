#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(){}

Fixed::~Fixed(){}

Fixed::Fixed(const int raw){
	_value = (int)(raw * (1 << _nbFractBits));
}

Fixed::Fixed(const float raw){
	_value = (int)(roundf(raw * (1 << _nbFractBits)));
}

Fixed::Fixed(const Fixed &src){
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &rhs){
	this->_value = rhs.getRawBits();
	return (*this);
}


int Fixed::getRawBits(void) const{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw){
	this->_value = raw;
}

float Fixed::toFloat(void) const{
	return ((float)this->getRawBits() / (float)(1 << _nbFractBits));
}

int	Fixed::toInt(void) const{
	return ((int)this->getRawBits() / (int)(1 << _nbFractBits));
}

Fixed	&Fixed::max(Fixed &a, Fixed &b){
	return (a.getRawBits() > b.getRawBits() ? a : b);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b){
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

const Fixed	&Fixed::max(Fixed const &a, Fixed const &b){
	const Fixed &res = a.getRawBits()  > b.getRawBits() ? a : b;
	return (res);
}


const Fixed	&Fixed::min(Fixed const &a, Fixed const &b){
	const Fixed &res = a.getRawBits() < b.getRawBits() ? a : b;
	return (res);
}

/*						operators					*/

std::ostream &operator<<(std::ostream & out, Fixed const & rhs){
	return (out << rhs.toFloat());
}

Fixed	Fixed::operator+(const Fixed &rhs) const{
	return (Fixed (this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &rhs) const{
	return (Fixed (this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &rhs) const{
	return (Fixed (this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &rhs) const{
	return (Fixed (this->toFloat() / rhs.toFloat()));
}

bool	Fixed::operator>(const Fixed &rhs) const{
	return (this->_value > rhs.getRawBits());
}

bool	Fixed::operator<(const Fixed &rhs) const{
	return (this->_value < rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed &rhs) const{
	return (this->_value >= rhs.getRawBits());
}

bool	Fixed::operator<=(const Fixed &rhs) const{
	return (this->_value <= rhs.getRawBits());
}

bool	Fixed::operator==(const Fixed &rhs) const{
	return (this->_value == rhs.getRawBits());
}

bool	Fixed::operator!=(const Fixed &rhs) const{
	return (this->_value != rhs.getRawBits());
}

Fixed	&Fixed::operator++(){
	++(this->_value);
	return (*this);
}

Fixed	Fixed::operator++(int){
	Fixed inc(*this);
	(this->_value)++;
	return (inc);
}

Fixed	&Fixed::operator--(){
	--(this->_value);
	return (*this);
}

Fixed	Fixed::operator--(int){
	Fixed dec(*this);
	(this->_value)--;
	return (dec);
}