#include <iostream>
#include "String.h"
#include "CommandHelper.h"
#include "ShapeContainer.h"
#include "Program.h"
#include "Line.h"
#include "Circle.h"
#include "Rectangle.h"

bool isAlreadyOpened(bool& filestatus);
void startProgram();
int main() {

	startProgram();
	return 0;
}

void startProgram() {
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
		if (commandNumber < HELP && isOpened == false)
		{
			std::cout << "You need to open file first" << std::endl;
		}
		else {
			switch (commandNumber)
			{
				case CREATE:
					myProgram.create();
					break;
				case ERASE:
					std::cout << "Please enter position: ";
					std::cin >> position;
					myProgram.erase(position);
					std::cin.ignore();
					break;
				case TRANSLATE:
					myProgram.translate();
					break;
				case WITHIN:
					myProgram.isWithin();
					break;
				case PRINT:
					myProgram.print();
					break;
				case OPEN:
					myProgram.open();
					isOpened = true;
					break;
				case CLOSE:
					if (isAlreadyOpened(isOpened))
					{
						isOpened = false;
						std::cout << "File is closed!\n";
					}
					break;
				case EXIT:
					if (isOpened == false)
					{
						isRunning = false;
						std::cout << "Exited";
					}
					else {
						std::cout << "You need to close the file first" << std::endl;
					}
					break;
				case SAVE:
					if (isAlreadyOpened(isOpened))
					{
						myProgram.save();
					}
					break;
				case HELP:
					CommandHelper::printCommands();
					break;
				case NOT_FOUND:
					std::cout << "CommandNotFound << beep boop" << std::endl;
					break;
			}
		}
	} while (isRunning);
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