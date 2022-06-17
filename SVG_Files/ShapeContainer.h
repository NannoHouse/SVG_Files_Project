#pragma once
#include "Shape.h"
#include <iostream>
class ShapeContainer {
private:
	Shape** f_shapes;
	 int size;
	 int capacity;

	 //aditional functions
	void copy(const ShapeContainer& other);
	void clean();
	void resize(int newCapacity);

public:
	ShapeContainer(unsigned int capacity = 16);
	ShapeContainer(const ShapeContainer& other);
	ShapeContainer& operator=(const ShapeContainer& other);
	~ShapeContainer();

	void add(Shape* newShape);
	void print();
	void erase(unsigned int position);
	void translate(int width, int hight, int position);
	bool within();//TODO

	//friend std::ifstream& operator>>(std::ifstream& in, ShapeContainer& container);

};