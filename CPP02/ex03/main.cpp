#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(5.0f, 10.0f);

	Point p1(5.0f, 5.0f);
	Point p2(0.0f, 0.0f);
	Point p3(10.0f, 10.0f);
	Point p4(5.0f, 0.0f);

	std::cout << "Point (5, 5) is inside: " << (bsp(a, b, c, p1) ? "true" : "false") << std::endl;
	std::cout << "Point (0, 0) is inside: " << (bsp(a, b, c, p2) ? "true" : "false") << std::endl;
	std::cout << "Point (10, 10) is inside: " << (bsp(a, b, c, p3) ? "true" : "false") << std::endl;
	std::cout << "Point (5, 0) is inside: " << (bsp(a, b, c, p4) ? "true" : "false") << std::endl;

	return (0);
}
