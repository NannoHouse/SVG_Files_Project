#pragma once
#include "String.h"
#include "Shape.h"

class Rectangle:public Shape {
private:
	unsigned int startX, startY;
	unsigned int width, hight;
	String color;
	void copy();
public:
	Rectangle(unsigned int _startX, unsigned int startY, unsigned int _width, unsigned int _hight, String _color);
	Rectangle(const Rectangle& other);
	virtual Shape* clone()const override;
	virtual void print()const override;
	virtual void read()const override;


};