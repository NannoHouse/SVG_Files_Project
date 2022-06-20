#include "String.h"
#include <iostream>
#include <string>


String::String(const char* word)
{
	myString = new char[strlen(word) + 1];
	strcpy_s(myString, strlen(word) + 1, word);
}

String::String(const String& other)
{
	this->myString = new char[other.getSize() + 1];
	strcpy_s(myString, other.getSize() + 1, other.getSymbols());
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
			delete[] myString;
		myString = new char[strlen(other.getSymbols()) + 1];
		strcpy_s(myString, other.getSize() + 1, other.getSymbols());
	}
	return *this;
}

String::~String()
{
	delete[] myString;
}

int String::getSize() const
{
	if (myString)
	{
		return strlen(myString);

	}
	else
		return 0;
}

void String::print() const
{
	if (myString)
	{
		std::cout << myString;
	}
} // maybe not needed if we have cout 
void String::add(const char* str)
{
	char* temp = new char[strlen(myString) + strlen(str) + 1];
	strcpy_s(temp, strlen(myString) + strlen(str) + 1, myString);
	strcat_s(temp, strlen(myString) + strlen(str) + 1, str);
	delete[] myString;
	myString = temp;
}

const char* String::getSymbols() const
{
	return myString;
}

bool String::contains(const String& segment) const
{
	if (strstr(myString, segment.getSymbols()))
	{
		return true;
	}
	else {
		return false;
	}
}

char* String::toLower()
{
	int i = 0;
	int size = strlen(myString);

	char* makeMeLower = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		makeMeLower[i] = makeLowerCase(this->myString[i]);
	}
	makeMeLower[size] = '\0';
	return makeMeLower;
}

bool String::operator<(const String& string) const
{
	if (strcmp(this->myString, string.myString) < 0)
	{
		return true;
	}
	return false;
}

bool String::operator==(const String& string) const
{
	if (strcmp(this->myString, string.myString) == 0)
	{
		return true;
	}
	return false;
}

bool String::operator!=(const String& string) const
{
	if (*this == string) {
		return false;
	}
	else
		return true;

}

std::ostream& operator<<(std::ostream& out, const String& str)
{
	out << str.myString;
	return out;
}

std::istream& operator>>(std::istream& in, String& str)
{
	char* buffer = new char[1024];
	in.getline(buffer, 1024);
	if (str.myString)
	{
		delete str.myString;
		str.myString = nullptr;
	}
	str.myString = new char[strlen(buffer) + 1];
	strcpy_s(str.myString, strlen(buffer) + 1, buffer);
	delete[] buffer;
	return in;
}

char String::makeLowerCase(char symbol)
{
	if (symbol >= 'A' && symbol <= 'Z')
		return symbol + ('a' - 'A');

	return symbol;
}

bool String::compareWithLowerCh(String& other)
{
	String comparable1 = this->toLower();
	String comparable2 = other.toLower();

	if (strcmp(comparable1.myString, comparable2.myString) == 0)
	{
		return true;
	}
	else {
		return false;
	}
}

 char String::charAt(int index)const 
{
	if (index > getSize() - 1 || index < 0) {
		std::cout << "Not entered correct position" << std::endl;
	}

	return myString[index];
}


