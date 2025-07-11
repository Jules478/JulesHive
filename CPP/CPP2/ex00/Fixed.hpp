#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
			int _fixedPoint;
			static const int _fractional;

	public:
			Fixed();
			Fixed(const Fixed& fixed);
			Fixed& operator=(const Fixed& fixed);
			~Fixed();

			int getRawBits(void) const;
			
			void setRawBits(int const raw);
};

#endif