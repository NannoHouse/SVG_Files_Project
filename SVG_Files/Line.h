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

	//getters and setters?
	virtual void print() const override;
	//virtual void read(td::ifstream& stream)  const  override; // da podavame potok po referenciq i da chetem ot veche opened file - std::ifstream& in
	  Shape* clone();

};