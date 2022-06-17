#include "Line.h"
#include <iostream>
Line::Line(unsigned int _startX, unsigned int _startY, unsigned int _endX, unsigned int _endY, String _color)
{
	startX = _startX;
	startY = _startY;
	endX = _endX;
	endY = _endY;
	color = _color;
}
Line::Line(const Line& other)
{
	startX = other.startX;
	startY = other.startY;
	endX = other.endX;
	endY = other.endY;
	color = other.color;
}
void Line::print() const
{
	std::cout << "line " << startX << ' ' << startY << ' ' << endX << ' ' << endY << ' ' << color << std::endl;
}

String Line::getType()
{
	return "line";
}

Shape* Line::clone() 
{
	return new Line(*this);
}

int Line::getStartX() const
{
	return startX;
}

int Line::getStartY() const
{
	return startY;
}

int Line::getEndX() const
{
	return endX;
}

int Line::getEndY() const
{
	return endY;
}
