#pragma once
#include<cstring>
#include<iostream>
const int Create = 1;// creates and adds
const int Erase = 2;
const int Translate = 3;
const int Within = 4;
const int Print = 5;
const int notFound = 0;
const int Open = 10;
const int Close = 11;
const int Exit = 12;
const int Save = 13;
const int Help = 0;


///Class CommandHelper hold all the commands that a user can do
class CommandHelper {
public:
	static int getCommand(const String command);
	static void printCommands();
};


/// getCommand accepts a string and returns the command that is equal to it
int CommandHelper::getCommand(const String command)
{
	if (command.contains("create"))
	{
		return Create;
	}
	else if (command.contains( "erase"))
	{
		return Erase;
	}
	else if (command.contains("translate"))
	{
		return Translate;
	}
	else if (command.contains("within"))
	{
		return Within;
	}
	else if (command.contains("print"))
	{
		return Print;
	}
	else if (command.contains("open"))
	{
		return Open;
	}
	else if (command.contains("close"))
	{
		return Close;
	}
	else if (command.contains("exit"))
	{
		return Exit;
	}
	else if (command.contains("save"))
	{
		return Save;
	}
	else if (command.contains("help"))
	{
		return Help;
	}
	else 
	{
		return notFound;
	}

	return 0;
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

