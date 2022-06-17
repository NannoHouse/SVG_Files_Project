#include "ShapeContainer.h"
#include <iostream>
#include <string>

#include "Shape.h"
#include "Line.h"
#include "Circle.h"
#include "Rectangle.h"
ShapeContainer::ShapeContainer(unsigned int capacity) : capacity(capacity), size(0)
{
	f_shapes = new Shape* [capacity];
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


void ShapeContainer::copy(const ShapeContainer& other)
{
	size = other.size;
	capacity = other.capacity;
	f_shapes = new Shape* [capacity];

	for ( int i = 0; i < size; i++)
	{
		f_shapes[i] = other.f_shapes[i]->clone();
	}
}

void ShapeContainer::clean()
{
	for (int i = 0; i < size; i++)
	{
		delete f_shapes[i];
	}

	delete[] f_shapes;
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

void ShapeContainer::print()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << i << ' ';
		f_shapes[i]->print();
	}
}

void ShapeContainer::erase(unsigned int position) 
{
	String type = f_shapes[position]->getType();
	delete f_shapes[position];

	for (int i = position; i < size - 1; i++)
	{
		f_shapes[i] = f_shapes[i + 1];
	}
	size--;
	std::cout << "Erased a "<< type<< '(' << position<<')'<<std::endl;
}

void ShapeContainer::resize(int newCapacity)
{
	if (newCapacity < capacity)
	{
		return;
	}

	capacity = newCapacity;
	Shape** new_Array = new Shape* [capacity];

	for ( int i = 0; i < size; i++)
	{
		new_Array[i] = f_shapes[i];
	}

	delete[] f_shapes;
	f_shapes = new_Array;
}
