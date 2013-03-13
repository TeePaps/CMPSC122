// main.cpp - Complex number program main entry point
// Written by Ted Papaioannou

// # -> Preprocessor directive
#include <iostream> // standard template library, defines stuff
#include "Complex.h" // "" -> directory
using namespace std;

void main ()
{
	
	// Declare variables first time used

	Complex<int> x,y;

	// Complex numbers
	Complex<float> a(10.0f, 7.0f);

	Complex<float> b(-10.0f, -7.0f);

	Complex<double> d(10.0, 7.0);

	Complex<double> e(10.0, 7.0);

	float real = 2;

	float zero = 0;

	Complex<float> c;

	// Testing float + operator;
	c = a + real; 
	cout << "c = " << c.Re << "+ i" << c.Im << endl;
	cout << "Should print 12 + i7" << endl << endl;

	c = a - zero; 
	cout << "c = " << c.Re << "+ i" << c.Im << endl;
	cout << "Should print 10 + i7" << endl << endl;

	// Testing float - operator;
	c = a - real; 
	cout << "c = " << c.Re << "+ i" << c.Im << endl;
	cout << "Should print 8 + i7" << endl << endl;

	c = a - zero; 
	cout << "c = " << c.Re << "+ i" << c.Im << endl;
	cout << "Should print 10 + i7" << endl << endl;

	// Testing float * operator
	c = a*real;
	cout << "c = " << c << endl;
	cout << "Should print 20 + i14" << endl << endl;

	c = a*zero;
	cout << "c = " << c << endl;
	cout << "Should print 0 + i0" << endl << endl;


	// Test float division
	try
	{
		c=a/real;
		cout << "c = " << c << endl;
		cout << "Should print 5 + i3.5" << endl << endl;

		cout << "Next operation should throw exception" << endl;
		c=a/zero; // Should throw exception
	}

	catch(char* error)
	{
		cout << "Exception occured. " << error << endl << endl;
	}
	

	// Testing == operator
	cout << (a == b) << endl;
	cout << "Should print 0" << endl << endl;

	cout << (d == e) << endl;
	cout << "Should print 1" << endl << endl;

	// Testing != operator
	cout << (a != b) << endl;
	cout << "Should print 1" << endl << endl;

	cout << (d != e) << endl;
	cout << "Should print 0" << endl << endl;

	system("pause");
}