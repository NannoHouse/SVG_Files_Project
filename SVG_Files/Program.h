#pragma once
#include "ShapeContainer.h"
#include <fstream>
class Program {
private:
	ShapeContainer container;
	String firstLineOfFIle, secondLineOfFile,thirdLineOfFile;
public:
	void create() {
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

};