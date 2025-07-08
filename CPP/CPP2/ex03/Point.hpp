#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <cmath>
# include "Fixed.hpp"

class Point
{
	private:
			const Fixed x;
			const Fixed y;

	public:
			Point();
			Point(Fixed x, Fixed y);
			Point(const Point& point);
			Point& operator=(const Point& point);
			~Point();
			const Fixed &getX() const;
			const Fixed &getY() const;

};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif