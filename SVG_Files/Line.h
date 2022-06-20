#pragma once
#include "Shape.h"
#include "String.h"


///Class Line inherits class Shape and is responsible for the shape Line
class Line :public Shape {
private:
	unsigned int startX, startY;
	unsigned int endX, endY;
	String color;
public:

	//constructor with parameters
	Line(unsigned int _startX=0, unsigned int _startY=0, unsigned int _endX=0, unsigned int _endY=0, String _color="no color");


	//setX sets start and end x to equal the number
	void setX( int& number) override ;


	//sety sets start and end y to equal the number
	void setY( int& number) override;


	//getX returns the value of the start x
	int getX() const override;


	//GetY returns the value of start y
	int getY() const override;


	//getEndX returns the value of the end x
	int getEndX()const;


	//getEndY returns the value of the end y
	int getEndY()const;


	/// isWithinCircle checks if the line is inside the giver rectangle
	bool isWithinCircle(int cx, int cy, int radius) override;


	/// isWithinRectangle checks if the line is inside the giver rectangle
	bool isWithinRectangle(int rx, int ry, int width, int hight) override;


	//clone creates a new circle with the same values and returns it
	Shape* clone() override;


	//getTye preturns the type of the shape
	virtual String getType();


	//print prints the line values on the console
	virtual void print() const override;


	//read reads values of a line
	virtual void read()  override;


	//write function writes line values in file
	virtual void write(std::ofstream& out) const override;
};