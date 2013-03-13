// String.cpp - String class implementation
// Written by Max I. Fomitchev-Zamilov

#include "String.h"
#include <sstream>

using namespace std;

// Default constructor
String::String()
{
	Text = NULL;
}

// MUST HAVE: Copy-constructor that performs deep copy
String::String(const String& source)
{
	Text = NULL;
	// Call the assignment operator to perform deep copy
	*this = source;
}

// Init-constructor to initialize this String with a C-string
String::String(const char* text)
{
	Text = NULL;
	// Call the assignment operator to perform deep copy
	*this = text;
}

// Init constructor, allocates this String to hold the size characters
String::String(int size)
{
	Text = new char[size];
}

// Destructor
String::~String()
{
	delete[] Text;
}

// Assignment operator to perform deep copy
String& String::operator = (const String& source)
{
	// Call the other assigment operator to perform deep copy
	*this = source.Text;
	return *this;
}

// Assignment operator to assign a C-string to this String
String& String::operator = (const char* text)
{
	// Ddispose of old Text
	delete[] Text;

	// +1 accounts for NULL-terminator
	int trueLength = GetLength(text) + 1;

	// Dynamically allocate characters on heap
	Text = new char[trueLength];

	// Copy all characters from source to Text; +1 accounts for NULL-terminator
	for ( int i = 0; i < trueLength; i++ )
		Text[i] = text[i];

	return *this;
}

// Returns a reference to a single character from this String
// String myString;
// char c = myString[1];
// myString[1] = 'c';
char& String::operator [] (int index) const
{
	CheckBounds(index, Text);
	return Text[index];
}

// Returns the count of characters in the String
int String::GetLength() const
{
	return GetLength(Text);
}

// Returns the count of characters in a C-string text; NULL-terminator is not counted
int String::GetLength(const char* text)
{
	int size = 0;
	while ( text[size] != '\0' )
	{
			size++;
	}
	return size;
}

char* String::GetText() const
{
	return Text;
}

// Comparison operators "==, !=, >, <"
bool String::operator == (const String& compareTo) const
{
	int index = 0;
	int size1 = (*this).GetLength();
	int size2 = compareTo.GetLength();
	if ( size1 == size2 )
	{
		while ( (index < size1) && (Text[index] == compareTo[index]) )
		{
			index++;
		}
		return ( index == size1 );
	}
	else
		return ( size1 == size2 );
}

bool String::operator != (const String& compareTo) const
{
	return !(*this == compareTo);
}

bool String::operator > (const String& compareTo) const
{
	int size1 = (*this).GetLength();
	int size2 = compareTo.GetLength();
	return ( size1 > size2 );
}

bool String::operator < (const String& compareTo) const
{
	return !( (*this) > compareTo );
}

// Concatenation operator
String String::operator + (const String& aString) const
{
	int size1 = GetLength(Text);
	int size2 = aString.GetLength();

	// +1 accounts for NULL-terminator
	int trueLength = size1 + size2 + 1;

	String concText = String(trueLength);
	

	// Copy all characters from source to concText; +1 accounts for NULL-terminator
	int i = 0;
	while ( i < trueLength )
	{
		if ( i < size1 )
		{
			concText[i] = Text[i];
		}
		else
		{
			concText[i] = aString[i-size1];
		}
		i++;
	}

	return concText;
}


String String::Substring(int startPosition, int length) const
{
	CheckBounds(startPosition, Text);
	String substring = String(length+1); // +1 for '\0'
	int endPoint = length + startPosition;
	int index = 0;

	while ( Text[startPosition] != '\0' && startPosition != endPoint)
	{
		substring[index++] = Text[startPosition++];
	}
	substring[index] = '\0';

	return substring;
}

int String::Find(char aChar, int startPosition) const
{
	CheckBounds(startPosition, Text);
	while ( Text[startPosition] != '\0' && Text[startPosition] != aChar)
	{
		startPosition++;
	}
	if ( Text[startPosition] != '\0')
	{
		return startPosition;
	}
	else
	{
		return NOT_FOUND;
	}
}


void String::CheckBounds(int index, const char* source) const
{
	int length = GetLength();

	// Check for valid index
	if ( (index < 0) || (index > length) )
	{
		stringstream error;
		error << "String::operator[] - index " << index <<
			" is out of bounds (0.." << (length - 1) << ")";
		throw String(error.str().c_str());
	}
}

// Stream output operator to print String to output stream
ostream& operator << (ostream& out, const String& myString)
{
	return out << myString.GetText();
}
