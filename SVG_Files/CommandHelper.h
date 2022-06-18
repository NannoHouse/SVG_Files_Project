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

class CommandHelper {
public:
	static int getCommand(const String command);

};
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
	else 
	{
		return notFound;
	}

	return 0;
}

