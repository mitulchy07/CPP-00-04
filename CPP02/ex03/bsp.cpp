#include "Fixed.hpp"
#include "Point.hpp"

static Fixed	sign(Point const p1, Point const p2, Point const p3)
{
	return ((p1.getX() - p3.getX()) * (p2.getY() - p3.getY())
			- (p2.getX() - p3.getX()) * (p1.getY() - p3.getY()));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed d1;
	Fixed d2;
	Fixed d3;
	bool  hasNeg;
	bool  hasPos;

	d1 = sign(point, a, b);
	d2 = sign(point, b, c);
	d3 = sign(point, c, a);

	hasNeg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	hasPos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return (!(hasNeg && hasPos));
}
