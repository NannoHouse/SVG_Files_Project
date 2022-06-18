#include "Circle.h"
#include <cmath>
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

void Circle::setX( int& number)
{
	startX = number;
}

void Circle::setY( int& number)
{
	startY = number;
}

int Circle::getX() const
{
	return startX;
}

int Circle::getY() const
{
	return startY;
}

int Circle::getRadius() const
{
	return radius;
}



void Circle::print()const
{
	std::cout << "circle " << startX << ' ' << startY << ' ' << radius << ' ' << color << std::endl;
}

String Circle::getType()
{
	return "circle";
}

bool Circle::isWithinCircle(int cx, int cy, int radius)
{
	double diameter = sqrt(pow(getX()-cx,2) + pow(getY()-cy,2));
	
	if (radius>(diameter + getRadius()))
	{
		return true;
	}
	return false;
}

bool Circle::isWithinRectangle(int rx, int ry, int width, int hight)
{
	
	if (getX()<= this->radius + rx && getY()<= this->radius + ry && getX() + this->radius <= rx+width && getY() + this->radius <= ry + hight)
	{
		return true;
	}
		return false;
}

void Circle::read()
{
}

Shape* Circle::clone()
{
	return new Circle(*this);
}
