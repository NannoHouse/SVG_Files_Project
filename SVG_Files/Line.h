#pragma once
#include "Shape.h"
#include "String.h"
class Line :public Shape {
private:
	unsigned int startX, startY;
	unsigned int endX, endY;
	String color;
public:
	Line(unsigned int _startX, unsigned int _startY, unsigned int _endX, unsigned int _endY, String _color);
	Line(const Line& other); // do i need this?
	bool isWithinCircle(int cx, int cy, int radius) override;
	bool isWithinRectangle(int rx, int ry, int width, int hight) override;

		//getters and setters
	void setX( int& number) override ;
	void setY( int& number) override;

	int getX() const override;
	int getY() const override;
	int getEndX()const;
	int getEndY()const;
	virtual void print() const override;
	Shape* clone() override;
	virtual String getType();
	//virtual void read(td::ifstream& stream)  const  override; // da podavame potok po referenciq i da chetem ot veche opened file - std::ifstream& in

};