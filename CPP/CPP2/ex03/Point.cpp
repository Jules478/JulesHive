# include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(Fixed const x, Fixed const y) : x(x), y(y)
{
}

Point::Point(const Point& point) : x(point.getX()), y(point.getY())
{
}

Point& Point::operator=(const Point& point)
{
	(void)point;
	return *this;
}

Point::~Point()
{
}

const Fixed &Point::getX() const
{
	return x;
}

const Fixed &Point::getY() const
{
	return y;
}