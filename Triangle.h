#pragma once
#include "Point.h"
#include "Shape.h"

class Triangle : public Shape	//8 + 16 + 16 + 16 ����Ʈ
{
public:
	Triangle();
	Triangle(const Point&, const Point&, const Point&);
	Triangle(const Triangle&);
	~Triangle();

	virtual void draw() const override;

private:
	Point p1{}, p2{}, p3{};
};

