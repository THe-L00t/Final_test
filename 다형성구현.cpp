//다형성 구현.cpp
#include "Point.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include "ShapeManager.h"

int main()
{
	ShapeManager sm(100);

	sm.insert(new Triangle());
	sm.insert(new Triangle(Point(0, 0), Point(1, 1), Point(2, 2)));
	sm.insert(new Circle(Point(1.23, 4.56), 7.89));

	for (int i = 0; i < 10; i++)
	{
		sm.insert(new Rectangle(Point(i, i + 1), Point(i * 2, i * 3)));
	}

	sm.draw();

}