#include "Circle.h"
#include <iostream>
Circle::Circle(unsigned int _startX, unsigned int _startY, unsigned int _radius, String _color)
{
	startX = _startX;
	startY = _startY;
	radius = _radius;
	color = _color;
}

void Circle::print()const
{
	std::cout << "circle " << startX << ' ' << startY << ' ' << radius << ' ' << color << std::endl;
}

Shape* Circle::clone() 
{
	return new Circle(*this);
}
