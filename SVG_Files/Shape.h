#pragma once
#include "String.h"
class Shape {
public:
	virtual  ~Shape() = default;
	virtual Shape* clone()  = 0;
	virtual void print() const = 0;
	virtual String getType() = 0;
	virtual bool isWithinCircle(int cx, int cy, int radius) = 0;
	virtual bool isWithinRectangle(int rx, int ry, int width, int hight) = 0;
	
	virtual void setX( int& number) =0;
	virtual void setY( int& number)=0;

	virtual int getX() const = 0;
	virtual int getY() const  = 0;



	//virtual void read(std::ifstream& stream) = 0;
};