#pragma once
#include<iostream>

///A personal implementation of std::string class
///consists only of a char * property
class String {
	// mysting class
private:
	char* myString;
public:
	/// big_4
	///Default constructor
	String(const char* word = "\0");

	///Copy constructor
	String(const String& other);

	///Assignment operator
	String& operator =(const String& other);

	///Destructor
	~String();

	///Gets the size of the string
	int getSize() const;

	///Gets the text inside the string 
	const char* getSymbols() const;

	///Puts another char * after the contents of the string
	void add(const char* str);

	///Prints the string to the screen
	void print() const;

	///Checks if the string contains another substring
	bool contains(const String& segment)const;

	///Returns the current string with only lowercase characters
	char* toLower();// needs to return a copy in order not to change header and lose info

	///makes a sybol lowercase
	char makeLowerCase(char symbol);

	///compares the lowercase version of a string to a anycase version of a string
	bool compareWithLowerCh(String& other);

	///Returns the chracter standing in a given position
	 char charAt(int index)const;

	// bool operators
	///Lexicographically checks if a string is smaller than another
	bool operator<(const String& string) const;

	///Checks if a string is equal to another
	bool operator==(const String& string)const;

	///Checks if a string is not equal to another one
	bool operator!=(const String& string) const;

	//friend functions
	friend std::ostream& operator<<(std::ostream& out, const String& str);
	friend std::istream& operator >> (std::istream& in, String& str);

};
