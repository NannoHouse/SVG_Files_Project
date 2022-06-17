#include "Rectangle.h"

Rectangle::Rectangle(unsigned int _startX, unsigned int _startY, unsigned int _width, unsigned int _hight, String _color)
{
	startX = _startX;
	startY = _startY;
	width = _width;
	hight = _hight;

}
Rectangle::Rectangle(const Rectangle& other)
{
	color = other.color;
	startX = other.startX;
	startY = other.startY;
	width = other.width;
	hight = other.hight;
}
Shape* Rectangle::clone()
{
	return new Rectangle(*this);
}

void Rectangle::print() const
{
	std::cout << "rectangle"
		<< ' ' << startX << ' ' << startY << ' ' << width << ' ' << hight << std::endl;

}

String Rectangle::getType()
{
	return "rectangle ";
}

void Rectangle::setStartX(unsigned int _startX)
{
	startX = _startX;
}

void Rectangle::setStartY(unsigned int _startY)
{
	startY = _startY;
}

int Rectangle::getStartX() const
{
	return startX;
}

int Rectangle::getStartY() const
{
	return startY;
}
