#pragma once
#include "Point.h"
#include "Shape.h"

class Rectangle : public Shape	//8 + 16 + 16 πŸ¿Ã∆Æ
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

