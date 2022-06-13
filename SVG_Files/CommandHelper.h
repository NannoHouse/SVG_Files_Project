#pragma once
#include<cstring>
#include<iostream>
const int Create = 1;// creates and adds
const int Erase = 2;
const int Translate = 3;
const int Within = 4;
const int Print = 5;
const int notFound = 0;
class CommandHelper {
	static int getCommand(const char* command);

};
int CommandHelper::getCommand(const char* command)
{
}

