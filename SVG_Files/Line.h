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

		//getters and setters
	void setStartX(unsigned int _startX) ;
	void setStartY(unsigned int _startY) ;
	void setEndX(unsigned int _endX) ;
	void setEndY(unsigned int _endX) ;

	int getStartX() const;
	int getStartY() const;
	int getEndX() const;
	int getEndY() const;

	virtual void print() const override;
	virtual String getType();
	//virtual void read(td::ifstream& stream)  const  override; // da podavame potok po referenciq i da chetem ot veche opened file - std::ifstream& in
	  Shape* clone();

};