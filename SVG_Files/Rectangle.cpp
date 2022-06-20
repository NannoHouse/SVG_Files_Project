#include "Rectangle.h"
#include <cmath>
Rectangle::Rectangle( int _startX,  int _startY,  int _width,  int _hight, String _color)
{
	startX = _startX;
	startY = _startY;
	width = _width;
	hight = _hight;
	color = _color;

}
Shape* Rectangle::clone()
{
	return new Rectangle(*this);
}

void Rectangle::print() const
{
	std::cout << "rectangle"
		<< ' ' << startX << ' ' << startY << ' ' << width << ' ' << hight <<' '<<color << std::endl;

}

String Rectangle::getType()
{
	return "rectangle ";
}

bool Rectangle::isWithinCircle(int cx, int cy, int radius)
{
	if (sqrt(pow(getX() - cx, 2) + pow(getY() - cy, 2))<radius &&
		sqrt(pow(getX() + this->width - cx, 2) + pow(getY() - cy, 2))<radius &&
		sqrt(pow(getX() + this->width - cx, 2) + pow(getY()+this->hight - cy, 2)) < radius&&
		sqrt(pow(getX() - cx, 2) + pow(getY()+ this->hight - cy, 2)) < radius)
	{
		return true;
	}
	return false;
}

bool Rectangle::isWithinRectangle(int rx, int ry, int width, int hight)
{
	if (rx<=getX() && ry <= getY() && rx + width >= (getX() + this->width) && ry+hight >= (getY()+ this->hight) )
	{
		return true;
	}
	return false;
}

void Rectangle::setX( int& number)
{
	startX += number;
}

void Rectangle::setY( int& number)
{
	startY += number;
}

int Rectangle::getX() const
{
	return startX;
}

int Rectangle::getY() const
{
	return startY;
}

void Rectangle::read()
{
	int x, y, width, hight;
	String color;
	std::cout << "Please enter X,Y, width, hight and color:";
	std::cin >> x >> y >> width>>hight >> color;
	this->startX = abs(x);
	this->startY = abs(y);
	this->width = abs(width);
	this->hight =abs( hight);
	this->color = color;
	
}

void Rectangle::write(std::ofstream& out) const
{
	out << "<rect x1 =\"" << getX() << "\" y1-=\"" << getY() << "\" width=\"" << this->width << "\" hight=\"" << this->hight << "\" fill=\"" << this->color << "\" />" << std::endl;
}

