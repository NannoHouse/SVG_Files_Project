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
	Circle(unsigned int _startX, unsigned int _startY, unsigned int _radius, String _color);
	Circle(const Circle& other); // do i need this

			//getters and setters
	 void setX( int& number) override;
	 void setY( int& number) override;
	
	 int getX() const override;
	 int getY() const override;
	 int getRadius()const;

	 void print()const override;
	 virtual String getType();
	  bool isWithinCircle(int cx, int cy, int radius) override;
	  bool isWithinRectangle(int rx, int ry, int width, int hight) override;
//	 virtual ~Circle() {};
	// void read(std::ifstream& stream)const override;
	 Shape* clone() override;

};