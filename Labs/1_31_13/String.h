// String.h - String clas declaration
// Written by Ted Papaioannou
//
// Assignment:
// string s = "something"
//				^C-string^
//
// Whenever you have non-template class, you should put code in .cpp file
//
#include <iostream>
#pragma once

#define NOT_FOUND = -1

class String
{
public:
	// Default Constructor: creates an empty or NULL string
	String();

	// Performs deep copy
	String(const String& copyFrom);

	// Init-constructor that initializes this String with a C-string
	String(const char* copyFrom);

	// Init-constructor that allocates string of a specified size
	String(int initialSize);

	// Deallocates memory allocated for the encapsulated C-string (Text)
	~String();

	// Assignment operator, performs deep copy
	String& operator = (const String& copyFrom);

	// Copes from C-string into this String
	String& operator = (const char* copyFrom);

	// Index operator, returns a character from the string; throws an exception
	// when the index is out of bounds (negative or past the null terminator)
	char& operator [] (int index) const;

	// Two string are equal when 1) the length is the same and 2) all characters are the same
	bool operator == (const String& compareTo) const;
	bool operator != (const String& compareTo) const;

	// Concatennates this String with appendix and returns new string;
	String operator + (const String& appendix) const;

	// Returns the length of the string, by scanning for the NULL terminator
	int GetLength() const;

	// Returns the length of the specified C-string (text)
	// Keyword "static": does not modify instance (non-static) data members
	// Static is shared between all members of class
	static int GetLength(const char* text);

	char* GetText() const;

	// Returns a new string, which is a substring of this String starting at
	// position and length characters long; if length is not specified (defaults to zero)
	// then the substring spans until the end of this String
	String Substring(int position, int length = 0) const;

	// Returns the index of a Char starting the search at position
	// returns NOT_FOUND when aChar is not present in this String
	int Find(char aChar, int position) const;

private:
	// The encapsulated C-string
	char* Text;
};

ostream& operator << (ostream& out, const String...