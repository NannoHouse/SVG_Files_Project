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
bool Line::isWithinCircle(int cx, int cy, int radius)
{
	return false;
}
bool Line::isWithinRectangle(int rx, int ry, int width, int hight)
{
	return false;
}
void Line::setX(unsigned int& number)
{
	startX += number;
	endX += number;
}
void Line::setY(unsigned int& number )
{
	startY += number;
	endY += number;
}
int Line::getX() const
{
	return startX;
}
int Line::getY() const
{
	return startY;
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

//int Line::getStartX() const
//{
//	return startX;
//}
//
//int Line::getStartY() const
//{
//	return startY;
//}
//
//int Line::getEndX() const
//{
//	return endX;
//}
//
//int Line::getEndY() const
//{
//	return endY;
//}
