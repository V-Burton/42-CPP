#pragma once
#include <string>
#include <iostream>

class Fixed{

	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &src);
		Fixed(const int r);
		Fixed(const float r);
		Fixed &operator=(const Fixed &rhs);


		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(Fixed const &a, Fixed const &b);
		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(Fixed const &a, Fixed const &b);

		bool operator>(const Fixed &rhs) const;
		bool operator<(const Fixed &rhs) const;
		bool operator>=(const Fixed &rhs) const;
		bool operator<=(const Fixed &rhs) const;
		bool operator==(const Fixed &rhs) const;
		bool operator!=(const Fixed &rhs) const;

		Fixed operator+(const Fixed &rhs) const;
		Fixed operator-(const Fixed &rhs) const;
		Fixed operator*(const Fixed &rhs) const;
		Fixed operator/(const Fixed &rhs) const;

		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);

	private:
		int _value;
		static const int _nbFractBits = 8;
};

std::ostream & operator<<(std::ostream &out, Fixed const &rhs);