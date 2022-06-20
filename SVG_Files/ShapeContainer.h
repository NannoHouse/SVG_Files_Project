#pragma once
#include "Shape.h"
#include <iostream>
///The heterogeneous container that contains all inherited classes from Shape class
///It has size, capacity and all shapes currently contained inside the container
class ShapeContainer {
private:
	Shape** f_shapes;
	 int size;
	 int capacity;

	///aditional functions
	 ///Copies the contents of another ShapeContainera into this one
	void copy(const ShapeContainer& other);

	///Cleans all currently added figures inside the container
	void clean();

	///Resizes the capacity of the ShapeContainer
	void resize(int newCapacity);

public:
	///A default constructor with default capacity set to 16
	ShapeContainer(unsigned int capacity = 16);

	///A copy constructor
	ShapeContainer(const ShapeContainer& other);

	///An assignment operator
	ShapeContainer& operator=(const ShapeContainer& other);

	///Destructor
	~ShapeContainer();

	///A method that adds a figure to the ShapeContainer using the copy base pure virtual method
	void add(Shape* newShape);

	///Gets the amount of figures inside the container
	int Size();

	///Prints the figures inside the container to the screen
	void print();

	///Erases a figure by given index
	void erase(const int& position); // validation outside

	///Translates a figure by given index with vertical and horizontal units
	void translate( int width, int hight, int position );

	///Prints all figures within a circle by given center coordinates (x,y) and radius
	void withinCircle(int x, int y, int radius);//TODO

	///Prints all figures within a rectangle by given (x,y,width,height)
	void withinRectangle(int x, int y, int width, int hight);//TODO

	///Writes all svg tags inside the svg container in a stream output
	void save(std::ofstream& out) const;

	//friend std::ifstream& operator>>(std::ifstream& in, ShapeContainer& container);

};