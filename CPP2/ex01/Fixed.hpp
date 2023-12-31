#pragma once
#include <iostream>
#include <string>

#define NBFRACTIONALBITS 8

class Fixed{
	public:
		Fixed();
		Fixed(const int raw);
		Fixed(const float raw);
		Fixed(const Fixed &src);
		Fixed &operator=(const Fixed &rhs);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int				_fixedPoint;
		static const	int _nbFractionalBits = NBFRACTIONALBITS;
};

std::ostream & operator<<(std::ostream & out, Fixed const & rhs);
