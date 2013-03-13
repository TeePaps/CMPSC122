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

	Complex d(-10.0f, 7.0f);

	Complex e(10.0f, -7.0f);

	// Adding two complex numbers together
	Complex c;
	float phi;

	// Testing + operator;
	c = a + b; // c = a.+(b); // a is the current instance of the class
	cout << "c = " << c << endl;
	cout << "Should print 0 + i0" << endl << endl;

	// Testing - operator;
	c = a - b; // c = -(a,b)
	cout << "c = " << c.Re << "+ i" << c.Im << endl;
	cout << "Should print 20.0 + i14" << endl << endl;

	// Testing * operator;
	c = a * b; // c = a.*(b); // a is the current instance of the class
	cout << "c = " << c << endl;
	cout << "Should print -149 + i-140" << endl << endl;

	//Testing / operator;
	c = a / b; // c = a.*(b); // a is the current instance of the class
	cout << "c = " << c << endl;
	cout << "Should print -0.342282 + i0" << endl << endl;

	cout << "Absolute value of c = " << c.Absolute() << endl << endl;

	// Testing Phasor() function
	phi = a.Phasor();
	cout << "phi = " << phi << " degrees " << endl;
	cout << "Should print 34.992 degrees" << endl << endl;

	// Testing Phasor() function
	phi = b.Phasor();
	cout << "phi = " << phi << " degrees " << endl;
	cout << "Should print -145.01 degrees" << endl << endl;

	// Testing Phasor() function
	phi = d.Phasor();
	cout << "phi = " << phi << " degrees " << endl;
	cout << "Should print 145.01 degrees" << endl << endl;


	// Testing Phasor() function
	phi = e.Phasor();
	cout << "phi = " << phi << " degrees " << endl;
	cout << "Should print -34.992 degrees" << endl << endl;
	

	system("pause");
}