#pragma once
#pragma once
#include "String.h"
#include "Shape.h"

///Class Circle inherits class Shape and is responsible for the shape Circle
class Circle : public Shape {
private:
	unsigned int startX, startY;
	unsigned int radius;
	String color;

public:

	///constructor with parameters 
	Circle(unsigned int _startX = 0, unsigned int _startY = 0, unsigned int _radius = 0, String _color = "no color");


	///setX sets x to equal given number
	void setX(int& number) override;


	///setY sets y to equal a given number
	void setY(int& number) override;


	///getX returns x value
	int getX() const override;


	///getY returns y value
	int getY() const override;


	///getRadius returns radius value
	int getRadius()const;


	///clone functon creates a new circle with the same values and returns it
	Shape* clone() override;


	///print prints circle values on the console
	void print()const override;


	///getType returns type of shape
	virtual String getType();


	/// isWithinCircle checks if the circle is inside the given circle
	bool isWithinCircle(int cx, int cy, int radius) override;


	/// isWithinRectangle checks if the circle is inside the giver rectangle
	bool isWithinRectangle(int rx, int ry, int width, int hight) override;


	/// read function reads all circle's values
	virtual void read()  override;


    /// write function writes the shape in the file
	virtual void write(std::ofstream& out) const override;

};