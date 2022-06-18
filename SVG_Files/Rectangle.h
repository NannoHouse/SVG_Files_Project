#pragma once
#include "String.h"
#include "Shape.h"

class Rectangle:public Shape {
private:
	 int startX, startY;
	 int width, hight;
	String color;
public:
	Rectangle( int _startX,  int _startY,  int _width,  int _hight, String _color);
	Rectangle(const Rectangle& other);
	virtual Shape* clone()override;
	 void print()const override;
	 virtual String getType();
	 bool isWithinCircle(int cx, int cy, int radius) override;
	 bool isWithinRectangle(int rx, int ry, int width, int hight) override;

	 //getters and setters
	 void setX( int& number) override;
	 void setY( int& number) override;

	 int getX() const override;
	 int getY() const override;


//	 virtual ~Rectangle() {};
	// void read(std::ifstream& stream)const override;


};