#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
			int _fixedPoint;
			static const int _fractional;

	public:
			Fixed();
			Fixed(const int point);
			Fixed(const float point);
			Fixed(const Fixed& fixed);
			Fixed& operator=(const Fixed& fixed);
			~Fixed();

			int getRawBits(void) const;
			
			void setRawBits(int const raw);

			float toFloat(void) const;
			int toInt(void) const;
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixed);

#endif