#include <iostream>
#include "Fixed.hpp"

int main( void )
{

	/////// SUBJECT TESTS ///////
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}

	/////// OWN TESTS ///////
	{
		Fixed a(12);
		Fixed b(6);
		Fixed c(3);
		Fixed d(2);
		Fixed e(0);

		// Basic Operators //
		std::cout << "12 + 6 = " << a + b << std::endl;
		std::cout << "12 - 6 = " << a - b << std::endl;
		std::cout << "2 * 3 = " << d * c << std::endl;
		std::cout << "6 / 2 = " << b / d << std::endl;

		// Comparison Operators //
		bool res;
		res = a > b;
		std::cout << "Is 12 > 6? " << res << " (1 = true | 0 = false)" <<std::endl;
		res = a < b;
		std::cout << "Is 12 < 6? " << res << " (1 = true | 0 = false)" << std::endl;
		res = a >= (b * d);
		std::cout << "Is 12 >= (6 * 2)? " << res << " (1 = true | 0 = false)" << std::endl;
		res = b >= (c * d);
		std::cout << "Is 6 <= (3 * 2)? " << res << " (1 = true | 0 = false)" << std::endl;
		res = d == (a / b);
		std::cout << "Is 2 == (12 / 6)? " << res << " (1 = true | 0 = false)" << std::endl;
		res = a != (b / d);
		std::cout << "Is 12 != 6 / 2? " << res << " (1 = true | 0 = false)" << std::endl;
	}
	{
		// Min/Max Function //
		Fixed a(10);
		Fixed b(20);
		
		Fixed& minRef = Fixed::min(a, b);
		Fixed& maxRef = Fixed::max(a, b);
		
		std::cout << "Min of " << a << " and " << b << " is " << minRef << std::endl;
		std::cout << "Max of " << a << " and " << b << " is " << maxRef << std::endl;
		
		minRef = Fixed(30);
		std::cout << "After modification, a is now: " << a << std::endl;
		
		// Static min/max Function //
		const Fixed c(15);
		const Fixed d(25);
		
		const Fixed& constMinRef = Fixed::min(c, d);
		const Fixed& constMaxRef = Fixed::max(c, d);
		
		std::cout << "Min of " << c << " and " << d << " is " << constMinRef << std::endl;
		std::cout << "Max of " << c << " and " << d << " is " << constMaxRef << std::endl;

		// This test will not compile
		// constMinRef = Fixed(40);
	}
	return 0;
}