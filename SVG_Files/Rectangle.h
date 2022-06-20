#pragma once
#include "String.h"
#include "Shape.h"

class Rectangle :public Shape {
private:
	int startX, startY;
	int width, hight;
	String color;
public:
	Rectangle(int _startX = 0, int _startY = 0, int _width = 0, int _hight = 0, String _color = "no color");

	virtual Shape* clone()override;
	void print()const override;
	virtual String getType();
	bool isWithinCircle(int cx, int cy, int radius) override;
	bool isWithinRectangle(int rx, int ry, int width, int hight) override;

	//getters and setters
	void setX(int& number) override;
	void setY(int& number) override;

	int getX() const override;
	int getY() const override;

	virtual void read()  override;
	virtual void write(std::ofstream& out) const override;

};