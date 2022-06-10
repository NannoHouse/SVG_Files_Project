#pragma once
class Shape {
public:
	~Shape() {};
	virtual Shape* clone() const = 0;
	virtual void print() const = 0;
	virtual void read() const = 0;
};