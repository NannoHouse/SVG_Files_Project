#pragma once
#include "ShapeContainer.h"
#include "Circle.h"
#include "Line.h"
#include "Rectangle.h"
#include <fstream>
#include <iostream>

class Program {
private:
	ShapeContainer container;
	String firstLineOfFIle, secondLineOfFile,thirdLineOfFile;
public:
	void create() {
		String shapetype;
		std::cout << "Please enter shape:";
		std::cin >> shapetype;
		if (shapetype == "circle")
		{
			createCircle();
		}
		else if (shapetype == "line")
		{
			createLine();
		}
		else {
			createRectangle();
		}
		//read from console
		
	}
	void isWithin() {
		//if in circle and rectangle 
	}
	void erase(unsigned int position) {
		container.erase(position); // verify position
	}
	void translate() {

	}
	void print() {
		container.print();
	}
	void open(String& file) {
		std::ifstream in;
		in.open("shapes.svg");
		if (in)
		{
			in>>firstLineOfFIle;
			in >> secondLineOfFile;
			in >> thirdLineOfFile;

		}
		else {
			std::cout << "Error at opening file\n";
		}
		in.close();
		std::cout << "Successfully opened figures.sv\n";
	}
	void save() {
		//write in file
	}

void createCircle() {
	
	Circle newCircle;
	newCircle.read();
	container.add(&newCircle);
}
void createLine() {
	Line line;
	line.read();
	container.add(&line);

}
void createRectangle() {

	Rectangle newRectangle;
	newRectangle.read();
	container.add(&newRectangle);
}
};
