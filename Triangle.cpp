#include <iostream>
#include "Triangle.h"

Triangle::Triangle() :p1{}, p2{}, p3{}
{
}

Triangle::Triangle(const Point& a, const Point& b, const Point& c) : p1{ a }, p2{ b }, p3{ c }
{
}

Triangle::Triangle(const Triangle& other) :p1 { other.p1 }, p2{ other.p2 }, p3{ other.p3 }
{
}

Triangle::~Triangle()
{
}

void Triangle::draw() const
{
	std::cout << " 그리는중 " << std::endl;
	std::cout << "삼각형 - (" << p1.x << "," << p1.y << "), (" << p2.x << "," << p2.y << "), (" << p3.x << "," << p3.y << ")" << '\n';
}
