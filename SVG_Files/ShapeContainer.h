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
	Shape& at(int index);
	void print();
	void erase(unsigned int position); // validation outside
	void translate(unsigned int width , unsigned int hight, unsigned int position );
	void withinCircle(int x, int y, int radius);//TODO
	void withinRectangle(int x, int y, int width, int hight);//TODO


	//friend std::ifstream& operator>>(std::ifstream& in, ShapeContainer& container);

};