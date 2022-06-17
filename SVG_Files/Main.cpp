#include <iostream>
#include "String.h"
int main() {
	String imput;
	bool isRunning = true;
	bool openedFile = false;
	do
	{

		std::cin >> imput;
		if (imput.contains("> open"))
		{
			openedFile = true;
			//call to read file and fill array
		}
		else if (imput == ">help")
		{
			//print commands
		}
		else if (imput == "> close")
		{
			//call to close file 
		}
		else if (imput == ">exit")
		{
			if (openedFile == true)
			{
				std::cout << "Your file is opened! Close it before exiting" << std::endl;
				break;
			}
			else {
				isRunning == false;
			}
		}
		else if (imput == "")
		{

		}


	} while (isRunning);

	return 0;
}