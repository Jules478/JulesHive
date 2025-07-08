#include "Point.hpp"

Fixed area(Fixed x1, Fixed y1, Fixed x2, Fixed y2, Fixed x3, Fixed y3)
{
	Fixed area_value = ((x1 * (y2-y3)) + (x2 * (y3 - y1)) + (x3 * (y1 - y2))) / 2;
	if (area_value < 0)
		area_value.setRawBits(area_value.getRawBits() * -1);
	return area_value;
}

bool bsp(Point const a, Point const b, Point const c, Point const p)
{
	Fixed ABC = area(a.getX(), a.getY(), b.getX(), b.getY(), c.getX(), c.getY());
	Fixed PAB = area(p.getX(), p.getY(), a.getX(), a.getY(), b.getX(), b.getY());
	Fixed PBC = area(p.getX(), p.getY(), b.getX(), b.getY(), c.getX(), c.getY());
	Fixed PAC = area(p.getX(), p.getY(), a.getX(), a.getY(), c.getX(), c.getY());
	
	Fixed total(PAB + PBC + PAC);
	if (total != ABC || PAB == 0 || PBC == 0 || PAC == 0)
		return false;
	else
		return true;
}