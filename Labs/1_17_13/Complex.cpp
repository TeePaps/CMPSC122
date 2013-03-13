// Complex.h - Complex type definition
// Written by Ted Papaioannou

#pragma once // EVERY header file created needs this!
// Use because you may use the same header twice
#include <iostream>

// User defined type (aka class) Complex
struct Complex
{
	// DATA MEMBERS
	// Real party of the complex number
	float Re;
	// Imaginary part of the complex number
	float Im;

	// Init-constructor (doubles as default constructor)
	Complex(float real = 0.0f, float imaginary = 0.0f /* default argument*/)
		// default argument must be at the end of the list
	{
		Re = real;
		Im = imaginary;
	}

	// Copy-constructor
	Complex(const Complex& source)
	{
		Re = source.Re;
		Im = source.Im;
	}

	// MEMBER FUNCTIONS (MEMBER OPERATORS)
	// Binary (means takes two operands) plus operator
	// Global operator for adding two complex numbers together
	// Operator that doesn't modify any members should be type const
	Complex operator + (const Complex& right) const
	{
		return Complex(Re + right.Re, Im + right.Im);
	}

	// Binary minus operator
	// Global operator for subtracting two complex numbers together
	Complex operator - (const Complex& b) const
	{
		return Complex(Re - b.Re, Im - b.Im);
	}

	// Absolute value member function
	float Absolute() const /* Means that the function does NOT modift class data members */
	{
		return sqrt(Re*Re + Im*Im);
	}
}; // ALWAYS put a semicolon at the end of struct or class
	// If it is missing, error list will tell you you're missing one in main
	// For online help: put cursor on text and click F1

// GLOBAL stream output operator for class Complex
// have to use ostream in order to use cout
ostream& operator << (ostream& out, const Complex& myComplex)
{
	return
		out << myComplex.Re << " + i" << myComplex.Im;
}

// Binary times operator
// Global operator for multiplying two complex numbers together
Complex operator * (Complex a, Complex b) 
{
	Complex result;
		result.Re = (a.Re * b.Re) + (a.Im * b.Im);
		result.Im = (a.Im * b.Re) + (a.Re * b.Im);
		return result;
}