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
	int Size();
	void print();
	void erase(const int& position); // validation outside
	void translate( int width, int hight, int position );
	void withinCircle(int x, int y, int radius);//TODO
	void withinRectangle(int x, int y, int width, int hight);//TODO
	void save(std::ofstream& out) const;

	//friend std::ifstream& operator>>(std::ifstream& in, ShapeContainer& container);

};