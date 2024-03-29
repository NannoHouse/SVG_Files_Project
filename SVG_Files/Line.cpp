#include "Line.h"
#include <cmath>

Line::Line(unsigned int _startX, unsigned int _startY, unsigned int _endX, unsigned int _endY, String _color)
{
	startX = _startX;
	startY = _startY;
	endX = _endX;
	endY = _endY;
	color = _color;
}

bool Line::isWithinCircle(int cx, int cy, int radius)
{
	double distanceStart = sqrt(pow(getX() - cx, 2) + pow(getY() - cy, 2));
	double distanceEnd = sqrt(pow(getEndX() - cx, 2) + pow(getEndY() - cy, 2));

	if (distanceStart <=radius && distanceEnd<= radius)
	{
		return true;
	}
		return false;
}
bool Line::isWithinRectangle(int rx, int ry, int width, int hight)
{
	if (getX()>=rx && getY() <= ry+hight && getEndX() <= rx+width && getEndY() <= ry+hight)
	{
		return true;
	}
	return false;
}

void Line::setX( int& number)
{
	startX += number;
	endX += number;
}
void Line::setY( int& number )
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
int Line::getEndX() const
{
	return endX;
}
int Line::getEndY() const
{
	return endY;
}

Shape* Line::clone() 
{
	return new Line(*this);
}
String Line::getType()
{
	return "line";
}

void Line::print() const
{
	std::cout << "line " << startX << ' ' << startY << ' ' << endX << ' ' << endY << ' ' << color << std::endl;
}
void Line::read()
{
	 int x, y, fx, fy;
	String color;
	std::cout << "Please enter x,y, fx, fy and color: ";
	std::cin >> x >> y >> fx >> fy >> color;
	this->startX  = abs(x);
	this->startY = abs(y);
	this->endX = abs(fx);
	this->endY = abs(fy);
	this->color = color;
}
void Line::write(std::ofstream& out) const
{
	out << "<line x1 =\"" << getX() << "\" y1-=\"" << getY() << "\" x2=\"" << getEndX() << "\" y2=\"" << getEndY() << "\" fill=\"" << this->color << "\" />" << std::endl;
}


