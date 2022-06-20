#pragma once
#include "String.h"
#include "Shape.h"


/// Class Rectangle inherits class Shape -> responds for the shape of a rectangle
class Rectangle :public Shape {
private:
	int startX, startY;
	int width, hight;
	String color;
public:

	/// constructor with parameters
	Rectangle(int _startX = 0, int _startY = 0, int _width = 0, int _hight = 0, String _color = "no color");


	/// clone function creates a new Shape of type Rectangle and returns it
	virtual Shape* clone()override;


	/// function print prints rectangle on the console 
	void print()const override;


	/// getType function returns the type of the shape
	virtual String getType();


	/// isWithinCircle checks if the Rectangle is inside the circle
	bool isWithinCircle(int cx, int cy, int radius) override;


	/// isWithinRectangle checks if the rectangle is inside the giver rectangle
	bool isWithinRectangle(int rx, int ry, int width, int hight) override;


	/// setX sets x to equal new value
	void setX(int& number) override;


	/// setY sets y to equal the new value
	void setY(int& number) override;


	/// getX returns the x value
	int getX() const override;


	/// getY returns the y value
	int getY() const override;


	/// read function reads all rectangle values
	virtual void read() override;


	/// write function writes the shape in the file
	virtual void write(std::ofstream& out) const override;

};