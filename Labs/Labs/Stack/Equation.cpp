/*// Main.cpp -
// Written by Ted Papaioannou

#include "Equation.h"

// Default constructor
Equation::Equation()
{
	MyEquation = NULL;
}

// MUST HAVE: Copy-constructor that performs deep copy
Equation::Equation(const Equation& source)
{
	MyEquation = NULL;

	*this = source;
}

// Init-constructor to initialize this String with a C-string
Equation::Equation(const char* text)
{
	MyEquation = NULL;
	// Call the assignment operator to perform deep copy
	*this = text;
}

// Init constructor, allocates this String to hold the size characters
Equation::Equation(int size)
{
	MyEquation = new char[size];
}

// Destructor
Equation::~Equation()
{
	delete[] MyEquation;
}

// Assignment operator to perform deep copy
String& String::operator = (const String& source)
{
	// Call the other assigment operator to perform deep copy
	*this = source.Text;
	return *this;
}

void Equation::CheckIfBalanced(char CharToMatch, Equation& myEquation) const
{
	switch ( CharToMatch )
	{
		case '(':
		case '[':
		case '{':
			myStack.push(exp[input]);
			break;
		default:
			throw  "Error - last " << CharToMatch << " did not match.";
	}

}

void Stack::GetInput(char input, Stack& myStack)
{
	switch ( input )
	{
	case '(':
	case '[':
	case '{': 
		myStack.push(exp[input]);
		break;
	case ')': Stack::Match('(', myStack);
		break;
	case ']': Stack::Match('[', myStack);
		break;
	case '}': Stack::Match('{', myStack);
		break;

	}

}
*/