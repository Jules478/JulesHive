#include "Fixed.hpp"

const int Fixed::_fractional = 8;

Fixed::Fixed() : _fixedPoint(0)
{
#ifdef MSG
	std::cout << "Default constructor called" << std::endl;
#endif
}

Fixed::Fixed(const int point)
{
#ifdef MSG
	std::cout << "Int constructor called" << std::endl;
#endif
	this->_fixedPoint = point << this->_fractional;
}

Fixed::Fixed(const float point)
{
#ifdef MSG
	std::cout << "Float constructor called" << std::endl;
#endif
	this->_fixedPoint = roundf(point * (1 << this->_fractional));
}

Fixed::Fixed(const Fixed& fixed)
{
#ifdef MSG
	std::cout << "Copy constructor called" << std::endl;
#endif
	this->_fixedPoint = fixed.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
#ifdef MSG
	std::cout << "Copy assignment operator called" << std::endl;
#endif
	if (this != &fixed)
		this->_fixedPoint = fixed.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
#ifdef MSG
	std::cout << "Destructor called" << std::endl;
#endif
}

int Fixed::getRawBits(void) const
{
#ifdef MSG
	std::cout << "getRawBits member function called" << std::endl;
#endif
	return _fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
	_fixedPoint = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_fixedPoint / (float)(1 << this->_fractional));
}

int Fixed::toInt(void) const
{
	return (this->_fixedPoint >> this->_fractional);
}

std::ostream &operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return o;
}

bool Fixed::operator>(Fixed fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool Fixed::operator<(Fixed fixed) const
{
	return (this->toFloat() < fixed.toFloat());
}

bool Fixed::operator>=(Fixed fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool Fixed::operator<=(Fixed fixed) const
{
	return (this->toFloat() <= fixed.toFloat());
}

bool Fixed::operator==(Fixed fixed) const
{
	return (this->toFloat() == fixed.toFloat());
}

bool Fixed::operator!=(Fixed fixed) const
{
	return (this->toFloat() != fixed.toFloat());
}

Fixed Fixed::operator+(Fixed fixed)
{
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(Fixed fixed)
{
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(Fixed fixed)
{
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(Fixed fixed)
{
	if (fixed._fixedPoint == 0)
	{
		std::cout << "Cannot divide by 0" << std::endl;
		return *this;
	}
	return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed Fixed::operator++()
{
	this->_fixedPoint++;
	return *this;
}

Fixed Fixed::operator--()
{
	this->_fixedPoint--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++this->_fixedPoint;
	return temp;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--this->_fixedPoint;
	return temp;
}

Fixed& Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1.toFloat() < fixed2.toFloat())
		return fixed1;
	else
		return fixed2;
}

const Fixed& Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1.toFloat() < fixed2.toFloat())
		return fixed1;
	else
		return fixed2;
}

Fixed& Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1.toFloat() > fixed2.toFloat())
		return fixed1;
	else
		return fixed2;
}

const Fixed& Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1.toFloat() > fixed2.toFloat())
		return fixed1;
	else
		return fixed2;
}
