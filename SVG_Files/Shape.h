#pragma once
#include "String.h"
class Shape {
public:
	//virtual  ~Shape() {};
	virtual Shape* clone()  = 0;
	virtual void print() const = 0;
	virtual String getType() = 0;
	//virtual void read(std::ifstream& stream) = 0;
};