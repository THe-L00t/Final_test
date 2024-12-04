#pragma once
#include "point.h"
#include "Shape.h"

class Circle : public Shape
{
public:
	Circle();
	Circle(const Point&, double);
	Circle(const Circle&);

	~Circle();

	virtual void draw() const override;

private:
	Point center{};
	double rad{};
};

