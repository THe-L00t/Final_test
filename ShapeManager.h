#pragma once
#include "shape.h"
class ShapeManager
{
	int nShape;
	int capacity;
	Shape** shapes;

public:
	explicit ShapeManager(int n);

	~ShapeManager();
	ShapeManager(const ShapeManager&) = default;

	Shape* operator[](int idx);
	

	void insert(Shape*);
	void remove(int);
	void draw() const;
	int getnShape();
	int getCapacity();
	void updateSM();

};

