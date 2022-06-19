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
	String firstLineOfFIle, secondLineOfFile, thirdLineOfFile;
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
	}
	void isWithin() {
		String shape;
		int newX, newY, width, hight, radius;
		std::cout << "Please enter shape type:";
		std::cin >> shape;
		if (shape == "circle")
		{
			std::cout << "Please enter X, Y and Radius: ";
			std::cin >> newX >> newY >> radius;
			container.withinCircle(newX, newY, radius);
			std::cin.ignore();
		}
		else if (shape == "Rectangle") {
			std::cout << "Please enter X, Y width and hight : ";
			std::cin >> newX >> newY >> width >> hight;
			container.withinRectangle(newX, newY, width, hight);
			std::cin.ignore();
		}
		//if in circle and rectangle 
	}
	void erase(unsigned int position) {
		container.erase(position); // verify position
	}
	void translate() {
		int width, hight, position = -1;
		std::cout << "Please enter width and hght";
		std::cin >> width>> hight;
		std::cout << "Do u have a specific position to translate/n Write -1 for no, or the exact position:";
		std::cin >> position;
		container.translate(width, hight, position);
		std::cin.ignore();
	}
	void print() {
		container.print();
	}
	void open(String& file) {
		std::ifstream in;
		in.open("shapes.svg");
		if (in)
		{
			in >> firstLineOfFIle;
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
		//Shape* p = &newRectangle;
		container.add(&newRectangle);
	}
};
