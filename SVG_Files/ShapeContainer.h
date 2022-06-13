#pragma once
#include "Shape.h"
#include <iostream>
class ShapeContainer {
private:
	Shape** f_shapes;
	unsigned int size;
	unsigned int capacity;


	void copy(const ShapeContainer& other);
	void clean();
	void resize(size_t newCapacity);

public:
	ShapeContainer(size_t capacity = 16);
	ShapeContainer(const ShapeContainer& other);
	ShapeContainer& operator=(const ShapeContainer& other);
	~ShapeContainer();

	void add(Shape* newShape);

	//friend std::ifstream& operator>>(std::ifstream& in, ShapeContainer& container);

};