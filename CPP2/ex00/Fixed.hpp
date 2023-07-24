#pragma once
#include <iostream>
#include <string>

#define NBFRACTIONALBITS 8

class Fixed{

	public:
		Fixed();
		Fixed(const Fixed &newFixed);
		Fixed &operator=(const Fixed &newFixed);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int _fixedPoint;
		static const int _nbFractionalBits;
};
