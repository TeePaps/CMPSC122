// main.cpp - Complex number program main entry point
// Written by Ted Papaioannou

// # -> Preprocessor directive
#include <iostream> // standard template library, defines stuff
#include "Complex.h" // "" -> directory
using namespace std;

void main ()
{
	// Declare variables first time used

	// Complex numbers
	Complex a(10.0f, 7.0f);

	Complex b(-10.0f, -7.0f);

	// Adding two complex numbers together
	Complex c;

	// Testing + operator;
	c = a + b; // c = a.+(b); // a is the current instance of the class
	cout << "c = " << c << endl;
	cout << "Should print 0 + i0" << endl << endl;

	// Testing * operator;
	c = a * b; // c = a.*(b); // a is the current instance of the class
	cout << "c = " << c << endl;
	cout << "Should print 0 + i0" << endl << endl;

	// Testing - operator;
	c = a - b; // c = -(a,b)
	cout << "c = " << c.Re << "+ i" << c.Im << endl;
	cout << "Should print 20.0 + i14" << endl << endl;

	cout << "Absolute value of c = " << c.Absolute();

	// cout << c; // << (cout,c);

	system("pause");
}