#pragma once
#include "Point.h"
#include "Shape.h"

class Rectangle : public Shape
{
public:
	Rectangle();
	Rectangle(const Point&, const Point&);
	Rectangle(const Rectangle&);
	~Rectangle();

	virtual void draw() const override;

private:
	Point p1, p2;
};

