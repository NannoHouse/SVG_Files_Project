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
//	Circle crcl(2,2,1,"pink");
	Circle crc2(5, 5, 10, "green");

	Rectangle rect(5,5,10,10,"black");
	Rectangle rect2(-1000, -1000, 10, 20, "white");
	Rectangle rect3(100, 60, 10, 10, "pink");

	//Line lin(2,3,4,5,"orange");
	//Line lin2(0, 0, 11, 5, "orange");

	
	container.add(&rect);
	container.add(&crc2);

	container.add(&rect2);
	container.add(&rect3);

	//container.add(&rect2);
	//container.add(&rect3);

	container.withinCircle(0,0,5);
	container.withinRectangle(0,0,30,30);

//	container.add(&rect);
	//container.add(&lin);
	//container.at(1).
	//container.translate(20, 1, 2);
	//container.print();

	
	return 0;
}