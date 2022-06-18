#pragma once
#include "ShapeContainer.h"

class Program {
private:
	ShapeContainer container;

public:
	void create();
	void isWithin();
	void erase();
	void translate();
	void print();
	void open();
	void save();
	void close();

};