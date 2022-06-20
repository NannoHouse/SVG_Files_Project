#pragma once
#include "ShapeContainer.h"
#include "Circle.h"
#include "Line.h"
#include "Rectangle.h"
#include <fstream>
#include <iostream>
#include <string>

///Class Program holds all the functions that are responsible for handling the work of the user
class Program {
private:
	ShapeContainer container;
	String firstLineOfFIle, secondLineOfFile, thirdLineOfFile;
public:

	/// create creates a shape and adds it to the container
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
		std::cout << "Successfuly created "<< shapetype<< " (" << container.Size()<<")\n";
	}


	///isWithin checks if all shapes in container are within a certain shape
	void isWithin() {
		String shape;
		int newX, newY, width, hight, radius;
		std::cout << "Please enter shape type:";
		std::cin >> shape;
		if (shape == "circle")
		{
			std::cout << "Please enter X, Y and Radius : ";
			std::cin >> newX >> newY >> radius;
			container.withinCircle(newX, newY, radius);
			std::cin.ignore();
		}
		else if (shape == "rectangle") {
			std::cout << "Please enter X, Y width and hight : ";
			std::cin >> newX >> newY >> width >> hight;
			container.withinRectangle(newX, newY, width, hight);
			std::cin.ignore();
		}
	}


	///erase removes a shape on a specific position from the container 
	void erase( int position) {
		if (position >= container.Size() )
		{
			std::cout << "Please enter valid position" << std::endl;
		}
		else
		container.erase(position); 
	}

	///translate translates all or one shape 
	void translate() {
		int width, hight, position = -1;
		std::cout << "Please enter hight and width: ";
		std::cin >> hight>> width;
		std::cout << "Do u have a specific position to translate?\n Write -1 for no, or the exact position: ";
		std::cin >> position;
		container.translate(width, hight, position);
		std::cin.ignore();
	}


	/// print prints all shapes on the console
	void print() {
		container.print();
	}


	/// open opens a file and reads it while filling the container with information from the file
	void open() {
		std::ifstream in;
		in.open("figures.svg");
		if (in)
		{
			String imput;
			in >> firstLineOfFIle;
			in >> secondLineOfFile;
			in >> thirdLineOfFile;
			in >> imput;
			while (imput != "</svg>")
			{
				if (imput.contains("circle"))
				{
					readCircle(imput);
				}
				else if (imput.contains("rect"))
				{
					readRect(imput);
				}
				else if (imput.contains("line"))
				{
					readLine(imput);
				}
				in>>imput;
			}
		}
		else {
			std::cout << "Error at opening file\n";
		}
		in.close();
		std::cout << "Successfully opened figures.svg\n";
	}


	///save saves the container with the changes in the file
	void save() {
		 std::ofstream out;
		out.open("figures.svg");
		if (out)
		{
			out<< firstLineOfFIle<<std::endl;
			out << secondLineOfFile<<std::endl;
			out << thirdLineOfFile<<std::endl;
			container.save(out);
			out << "</svg>";
		}
		else {
			std::cout << "Error at opening file\n";
		}
		out.close();
		std::cout << "Successfully saved in figures.sv\n";
	}
	private:


		/// createCircle creates a circle
	void createCircle() {

		Circle newCircle;
		newCircle.read();
		container.add(&newCircle);
	}


	///createLine creates a line
	void createLine() {
		Line line;
		line.read();
		container.add(&line);

	}


	/// createRectangle creates a Rectangle
	void createRectangle() {
		Rectangle newRectangle;
		newRectangle.read();
		container.add(&newRectangle);
	}


	/// readCircle reads a circle from the file
	void readCircle(String& imput) {
		int x=0, y=0, r=0;
		String color;
		int counterVariable = 4;
		bool hasOpened = false;
		std::string strNumber; // couldn't digure out how to do it 
		while (counterVariable != 0)
		{
			for (int i = 0; i < imput.getSize(); i++)
			{
				if (hasOpened && counterVariable !=0)
				{
					strNumber += imput.charAt(i);
				}
				if (imput.charAt(i) == '"' && hasOpened == false)
				{
					hasOpened = true;
				}
				else if (imput.charAt(i) == '\"' && hasOpened == true)
				{
					strNumber.pop_back();
					hasOpened = false;
					switch (counterVariable)
					{
					case 4:
						x = std::stoi(strNumber);
						counterVariable--;
						strNumber = "";
						break;
					case 3:
						y = std::stoi(strNumber);
						counterVariable--;
						strNumber = "";
						break;
					case 2:
						r = std::stoi(strNumber);
						counterVariable--;
						strNumber = "";
						break;
					case 1:
						color = strNumber.data();
						counterVariable--;
					}
				}
			}
			Circle newCirlce(x,y,r,color);
			container.add(&newCirlce);
		}
	}


	///readRect reads a rectangle from a file
	void readRect(String& imput) {
		int x = 0, y = 0, width = 0, hight = 0;
		String color;
		int counterVariable = 5;
		bool hasOpened = false;
		std::string strNumber; // couldn't digure out how to do it 
		while (counterVariable != 0)
		{
			for (int i = 0; i < imput.getSize(); i++)
			{
				if (hasOpened && counterVariable != 0)
				{
					strNumber += imput.charAt(i);
				}
				if (imput.charAt(i) == '"' && hasOpened == false)
				{
					hasOpened = true;
				}
				else if (imput.charAt(i) == '\"' && hasOpened == true)
				{
					strNumber.pop_back();
					hasOpened = false;
					switch (counterVariable)
					{
					case 5:
						x = std::stoi(strNumber);
						counterVariable--;
						strNumber = "";
						break;
					case 4:
						y = std::stoi(strNumber);
						counterVariable--;
						strNumber = "";
						break;
					case 3:
						width = std::stoi(strNumber);
						counterVariable--;
						strNumber = "";
						break;
					case 2:
						hight = std::stoi(strNumber);
						counterVariable--;
						strNumber = "";
						break;
					case 1:
						color = strNumber.data();
						counterVariable--;
					}
				}
			}
			Rectangle newRectangle(x, y, width, hight, color);
			container.add(&newRectangle);
		}
	}


	///readLine reads a line from a file
	void readLine(String& imput) {
		int x = 0, y = 0, fx = 0,fy=0;
		String color;
		int counterVariable = 5;
		bool hasOpened = false;
		std::string strNumber; // couldn't digure out how to do it 
		while (counterVariable != 0)
		{
			for (int i = 0; i < imput.getSize(); i++)
			{
				if (hasOpened && counterVariable != 0)
				{
					strNumber += imput.charAt(i);
				}
				if (imput.charAt(i) == '"' && hasOpened == false)
				{
					hasOpened = true;
				}
				else if (imput.charAt(i) == '\"' && hasOpened == true)
				{
					strNumber.pop_back();
					hasOpened = false;
					switch (counterVariable)
					{
					case 5:
						x = std::stoi(strNumber);
						counterVariable--;
						strNumber = "";
						break;
					case 4:
						y = std::stoi(strNumber);
						counterVariable--;
						strNumber = "";
						break;
					case 3:
						fx = std::stoi(strNumber);
						counterVariable--;
						strNumber = "";
						break;
					case 2:
						fy = std::stoi(strNumber);
						counterVariable--;
						strNumber = "";
						break;
					case 1:
						color = strNumber.data();
						counterVariable--;
					}
				}
			}
			Line newLine(x, y, fx,fy, color);
			container.add(&newLine);
		}
	}
};

