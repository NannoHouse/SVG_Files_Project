#pragma once
#include<iostream>
class String {
	// mysting class
private:
	char* myString;
public:
	// big_4
	//String();
	String(const char* word = "\0");
	String(const String& other);
	String& operator =(const String& other);
	~String();

	// functions
	int getSize() const;
	const char* getSymbols() const;
	void add(const char* str);
	void print() const;
	bool contains(const String& segment)const;
	char* toLower(); // needs to return a copy in order not to change header and lose info
	char makeLowerCase(char symbol);
	bool compareWithLowerCh(String& other);
	char* erase(String& substring);

	// bool operators
	bool operator<(const String& string) const;
	bool operator==(const String& string)const;
	bool operator!=(const String& string) const;

	//friend functions
	friend std::ostream& operator<<(std::ostream& out, const String& str);
	friend std::istream& operator >> (std::istream& in, String& str);

};
