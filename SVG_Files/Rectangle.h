#pragma once
#include "String.h"
#include "Shape.h"

class Rectangle:public Shape {
private:
	unsigned int startX, startY;
	unsigned int width, hight;
	String color;
public:
	Rectangle(unsigned int _startX, unsigned int _startY, unsigned int _width, unsigned int _hight, String _color);
	Rectangle(const Rectangle& other);
	virtual Shape* clone()override;
	 void print()const override;
	 virtual String getType();

	 //getters and setters
	 void setStartX(unsigned int _startX);
	 void setStartY(unsigned int _startY);

	 int getStartX() const;
	 int getStartY() const;
//	 virtual ~Rectangle() {};
	// void read(std::ifstream& stream)const override;


};