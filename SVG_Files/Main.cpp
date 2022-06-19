#include <iostream>
#include "String.h"
#include "CommandHelper.h"
#include "ShapeContainer.h"
#include "Program.h"
#include "Line.h"
#include "Circle.h"
#include "Rectangle.h"

bool isAlreadyOpened(bool& filestatus);
int main() {
	String imput;
	Program myProgram;
	bool isRunning = true;
	bool isOpened = false;

	int commandNumber;
	do
	{
		std::cin >> imput;
		commandNumber = CommandHelper::getCommand(imput);
		if (commandNumber <10 && isOpened == false)
		{
			std::cout << "You need to open file first"<<std::endl;
		}
		else {
			switch (commandNumber)
			{
			case 1:
				myProgram.create();
				break;
			case 2:
				int position;
				position = 2;
				myProgram.erase(position);
				break;
			case 3:
				myProgram.translate();
				break;
			case 4:
				myProgram.isWithin();
				break;
			case 5:
				myProgram.print();
				break;
			case 10:
				////remove command part
				//String fileName;
				//myProgram.open(fileName);
				isOpened = true;
				break;
			case 11:
				if (isAlreadyOpened(isOpened)) // needt to be opened for it to be closed
				{
					isOpened = false;
				}
				break;
			case 12:
				if (isOpened == false)
				{
					//myProgram.exit();
					isRunning = false;
				}
				else {
					std::cout << "YOu need to close the file first" << std::endl;
				}
				break;
			case 13:
				if (isAlreadyOpened(isOpened))
				{
					myProgram.save();
				}
				break;
			case 0:
				std::cout << "CommandNotFound << beep boop" << std::endl;
			}
		}
	} while (isRunning);

	//ShapeContainer container;
//	Circle crcl(2,2,1,"pink");
	//Circle crc2(5, 5, 10, "green");

	//Rectangle rect(5,5,10,10,"black");
	///Rectangle rect2(-1000, -1000, 10, 20, "white");
	//Rectangle rect3(100, 60, 10, 10, "pink");

	//Line lin(2,3,4,5,"orange");
	//Line lin2(0, 0, 11, 5, "orange");

	//
	//container.add(&rect);
	//container.add(&crc2);

	//container.add(&rect2);
	//container.add(&rect3);

	//container.add(&rect2);
	//container.add(&rect3);

	//container.withinCircle(0,0,5);
	//container.withinRectangle(0,0,30,30);
	//container.erase(2);

//	container.add(&rect);
	//container.add(&lin);
	//container.at(1).
	//container.translate(20, 1, 2);
	//container.print();


	return 0;
}

bool isAlreadyOpened(bool& filestatus)
{
	if (filestatus)
	{
		return true;
	}
	else {
		std::cout << "You need to open the file before exiting" << std::endl;
		return false;
	}

}