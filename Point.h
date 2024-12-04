#ifndef _Point
#define _Point

struct Point
{
	double x{ 0.0 }, y{ 0.0 };

	Point();
	Point(double, double);
	Point(const Point&) = default;
};
#endif
