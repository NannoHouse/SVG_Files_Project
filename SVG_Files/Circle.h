#pragma once
#pragma once
#include "String.h"
#include "Shape.h"
class Circle : public Shape{
private:
	unsigned int startX, startY;
	unsigned int radius;
	String color;

public:
	Circle(unsigned int _startX=0, unsigned int _startY=0, unsigned int _radius=0, String _color ="no color");
	
	 void setX( int& number) override;
	 void setY( int& number) override;
	
	 int getX() const override;
	 int getY() const override;
	 int getRadius()const;

	 Shape* clone() override;
	 void print()const override;
	 virtual String getType();
	  bool isWithinCircle(int cx, int cy, int radius) override;
	  bool isWithinRectangle(int rx, int ry, int width, int hight) override;

	 virtual void read()  override;
	 virtual void write(std::ofstream& out) const override;

};