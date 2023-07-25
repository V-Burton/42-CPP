#pragma once
#include <iostream>
#include <string>

#define NBFRACTIONALBITS 8

class Fixed{

	public:
		Fixed();
		Fixed(const Fixed &Fixed);
		Fixed &operator=(const Fixed &Fixed);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int _fixedPoint;
		static const int _nbFractionalBits = NBFRACTIONALBITS;
};
