#include <iostream>
#include "String.h"
#include "ShapeContainer.h"
#include "Line.h"
#include "Circle.h"
#include "Rectangle.h"
int main() {
	//String imput;
	//bool isRunning = true;
	//bool openedFile = false;
	//do
	//{

	//	std::cin >> imput;
	//	if (imput.contains("> open"))
	//	{
	//		openedFile = true;
	//		//call to read file and fill array
	//	}
	//	else if (imput == ">help")
	//	{
	//		//print commands
	//	}
	//	else if (imput == "> close")
	//	{
	//		//call to close file 
	//	}
	//	else if (imput == ">exit")
	//	{
	//		if (openedFile == true)
	//		{
	//			std::cout << "Your file is opened! Close it before exiting" << std::endl;
	//			break;
	//		}
	//		else {
	//			isRunning == false;
	//		}
	//	}
	//	else if (imput == "")
	//	{

	//	}


	//} while (isRunning);
	ShapeContainer container;
	Circle crcl(2,3,4,"pink");
	Rectangle rect(4,5,12,12,"black");
	Line lin(2,3,4,5,"orange");
	
	container.add(&crcl);
	container.add(&rect);
	container.add(&lin);
	//container.at(1).
	container.print();
	container.translate(20, 1, 2);

	
	return 0;
}