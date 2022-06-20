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
	int position = 0;
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
				std::cin >> position;
				myProgram.erase(position);
				std::cin.ignore();
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
				myProgram.open();
				isOpened = true;
				break;
			case 11:
				if (isAlreadyOpened(isOpened))
				{
					isOpened = false;
				}
				break;
			case 12:
				if (isOpened == false)
				{
					isRunning = false; 
				}
				else {
					std::cout << "Yuu need to close the file first" << std::endl;
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