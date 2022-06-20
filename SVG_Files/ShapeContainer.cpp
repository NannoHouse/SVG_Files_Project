#include "ShapeContainer.h"
#include <iostream>
#include <string>

#include "Shape.h"
#include "Line.h"
#include "Circle.h"
#include "Rectangle.h"
ShapeContainer::ShapeContainer(unsigned int capacity ) : capacity(capacity), size(0)
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
	for (int i = 0; i < size ; i++)
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

	f_shapes[size] = newShape->clone();
	size++;
}

int ShapeContainer::Size()
{
	return size;
}

void ShapeContainer::print()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << i+1 << ". ";
		f_shapes[i]->print();
	}
	std::cout << "ENDED PRINTING" << std::endl;

}

void ShapeContainer::erase(const int& position) 
{
	String type = f_shapes[position-1]->getType();

	for (int i = position-1; i < size  ; i++)
	{
		f_shapes[i] = f_shapes[i + 1];
	}
	size--;
	std::cout << "Erased a "<< type<< '(' << position<<')'<<std::endl;
}

void ShapeContainer::translate( int width,  int hight,  int position)
{
		if (position !=-1)
		{
			(*f_shapes[position]).setX(width);
			(*f_shapes[position]).setY(hight);
			std::cout << "Translated figure in position "<< position<< std::endl;
		}
		else {
			for (int i = 0; i < size; i++)
			{
				(*f_shapes[i]).setX(width);
				(*f_shapes[i]).setY(hight);
			}
			std::cout << "Translated all figures " << std::endl;
		}
}

void ShapeContainer::withinCircle(int x, int y, int radius)
{
	bool printed = false;
	for (int i = 0; i < size ; i++)
	{
		if ((*f_shapes[i]).isWithinCircle(x, y, radius))
		{
			f_shapes[i]->print();
			printed = true;
		}

	}
	if (printed == false)
	{
		std::cout << "No figures are located within circle " << x << ' ' << y << ' ' << radius<< '\n';
	}
	
}

void ShapeContainer::withinRectangle(int x, int y, int width, int hight)
{
	bool printed = false;
	for (int i = 0; i < size; i++)
	{
		if ((*f_shapes[i]).isWithinRectangle(x,y,width, hight))
		{
			f_shapes[i]->print();
			bool printed = true;
		}
	}
	if (printed == false)
	{
		std::cout << "No figures are located within circle "<< x<<' '<<y <<' '<< width <<' '<< hight << '\n';
	}
}

void ShapeContainer::save(std::ofstream& out) const
{
	for (int i = 0; i < size; i++)
	{
		f_shapes[i]->write(out);
	}
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
