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

			bool operator>(Fixed fixed) const;
			bool operator<(Fixed fixed) const;
			bool operator>=(Fixed fixed) const;
			bool operator<=(Fixed fixed) const;
			bool operator==(Fixed fixed) const;
			bool operator!=(Fixed fixed) const;

			Fixed operator+(Fixed fixed);
			Fixed operator-(Fixed fixed);
			Fixed operator*(Fixed fixed);
			Fixed operator/(Fixed fixed);

			Fixed operator++();
			Fixed operator--();
			Fixed operator++(int);
			Fixed operator--(int);

			static Fixed& min(Fixed &fixed1, Fixed &fixed2);
			static const Fixed& min(const Fixed &fixed1, const Fixed &fixed2);
			static Fixed& max(Fixed &fixed1, Fixed &fixed2);
			static const Fixed& max(const Fixed &fixed1, const Fixed &fixed2);
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixed);

#endif