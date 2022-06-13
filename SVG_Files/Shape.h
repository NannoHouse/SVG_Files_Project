#pragma once
#include<fstream>
class Shape {
public:
	~Shape() {};
	virtual Shape* clone()  = 0;
	virtual void print() const = 0;
	//virtual void read(std::ifstream& stream) = 0;
};