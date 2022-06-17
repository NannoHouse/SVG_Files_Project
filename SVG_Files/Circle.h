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
	 void setX(unsigned int& number) override;
	 void setY(unsigned int& number) override;
	
	 int getX() const override;
	 int getY() const override;

	 void print()const override;
	 virtual String getType();
//	 virtual ~Circle() {};
	// void read(std::ifstream& stream)const override;
	 Shape* clone() override;

};