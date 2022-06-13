#pragma once
#include "String.h"
#include "Shape.h"
class Circle : public Shape{
private:
	unsigned int startX, startY;
	unsigned int radius;
	String color;

public:
	Circle(unsigned int _startX, unsigned int _startY, unsigned int _radius, String _color);
	Circle(const Circle& other); // do i need this
	 void print()const override;
	// void read(std::ifstream& stream)const override;
	 Shape* clone();

};