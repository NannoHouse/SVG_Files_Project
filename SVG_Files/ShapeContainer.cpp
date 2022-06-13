#include "ShapeContainer.h"
#include <iostream>
#include <string>

#include "Shape.h"
#include "Line.h"
#include "Circle.h"
#include "Rectangle.h"
ShapeContainer::ShapeContainer(unsigned int capacity) : capacity(capacity), size(0)
{
	f_shapes = new Shape * [capacity];
}

ShapeContainer::ShapeContainer(const ShapeContainer& other)
{
	copy(other);
}

ShapeContainer& ShapeContainer::operator=(const ShapeContainer& other)
{
	if (this != &other)
	{
		clean();
		copy(other);
	}

	return *this;
}

ShapeContainer::~ShapeContainer()
{
	clean();
}


void ShapeContainer::add(Shape* newShape)
{
	if (size >= capacity)
	{
		resize(capacity * 2);
	}

	f_shapes[size] = newShape;
	size++;
}

void ShapeContainer::copy(const ShapeContainer& other)
{
	size = other.size;
	capacity = other.capacity;
	f_shapes = new Shape * [capacity];

	for ( int i = 0; i < size; i++)
	{
		f_shapes[i] = other.f_shapes[i]->clone();
	}
}

void ShapeContainer::clean()
{
	for (size_t i = 0; i < size; i++)
	{
		delete f_shapes[i];
	}

	delete[] f_shapes;
}

void ShapeContainer::resize(int newCapacity)
{
	if (newCapacity < capacity)
	{
		return;
	}

	capacity = newCapacity;
	Shape** newShapes = new Shape * [capacity];

	for ( int i = 0; i < size; i++)
	{
		newShapes[i] = f_shapes[i];
	}

	delete[] f_shapes;
	f_shapes = newShapes;
}
