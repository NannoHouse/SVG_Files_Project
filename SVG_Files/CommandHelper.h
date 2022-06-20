#pragma once
#include<cstring>
#include<iostream>


enum COMMANDS {
	CREATE, ERASE, TRANSLATE, WITHIN, PRINT, CLOSE, SAVE, SAVE_AS, HELP, NOT_FOUND, EXIT, OPEN
};

///Class CommandHelper hold all the commands that a user can do
class CommandHelper {
public:
	static COMMANDS getCommand(const String& command);
	static void printCommands();
};


/// getCommand accepts a string and returns the command that is equal to it
COMMANDS CommandHelper::getCommand(const String& command)
{
	if (command.contains("create"))
	{
		return CREATE;
	}
	else if (command.contains( "erase"))
	{
		return ERASE;
	}
	else if (command.contains("translate"))
	{
		return TRANSLATE;
	}
	else if (command.contains("within"))
	{
		return WITHIN;
	}
	else if (command.contains("print"))
	{
		return PRINT;
	}
	else if (command.contains("open"))
	{
		return OPEN;
	}
	else if (command.contains("close"))
	{
		return CLOSE;
	}
	else if (command.contains("exit"))
	{
		return EXIT;
	}
	else if (command.contains("save"))
	{
		return SAVE;
	}
	else if (command.contains("help"))
	{
		return HELP;
	}
	else 
	{
		return NOT_FOUND;
	}

}

///command prints out all possible commands 
void CommandHelper::printCommands() {

	std::cout << "The following commands are supported:\n";
	std::cout << "Open <File>     opens <file>\n" ;
	std::cout << "close           closes currently opened file\n";
	std::cout << "save            saves the current open file \n";
	std::cout << "saveAs <File>   save the currently open file in <file> \n";
	std::cout << "help            prints this information  \n";
	std::cout << "exit            exits the program  \n";

}

