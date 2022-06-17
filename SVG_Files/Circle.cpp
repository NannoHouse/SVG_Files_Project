#include "Circle.h"
#include <iostream>
Circle::Circle(unsigned int _startX, unsigned int _startY, unsigned int _radius, String _color)
{
	startX = _startX;
	startY = _startY;
	radius = _radius;
	color = _color;
}

Circle::Circle(const Circle& other)
{
	startX = other.startX;
	startY = other.startY;
	radius = other.radius;
	color = other.color;
}

void Circle::setStartX(unsigned int _startX)
{
	startX = _startX;
}

void Circle::setStartY(unsigned int _startY)
{
	startY = _startY;
}

int Circle::getStartX() const
{
	return startX;
}

int Circle::getStartY() const
{
	return startY;
}

void Circle::print()const
{
	std::cout << "circle " << startX << ' ' << startY << ' ' << radius << ' ' << color << std::endl;
}

String Circle::getType()
{
	return "circle";
}

Shape* Circle::clone() 
{
	return new Circle(*this);
}
