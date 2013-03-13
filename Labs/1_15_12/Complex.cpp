// Complex.h - Complex type definition
// Written by Ted Papaioannou

#pragma once // EVERY header file created needs this!
// Use because you may use the same header twice

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

	// MEMBER FUNCTIONS (MEMBER OPERATORS)
	// Binary (means takes two operands) plus operator
	// Global operator for adding two complex numbers together
	Complex operator + (/*Complex left,*/ Complex right) 
	{
		Complex result;
			result.Re = this->Re + right.Re;
			result.Im = this->Im + right.Im;
			return result;
	}

	// Binary minus operator
	// Global operator for subtracting two complex numbers together
	Complex operator - (/*Complex a,*/ Complex b) 
	{
		Complex result;
			result.Re = Re - b.Re;
			result.Im = Im - b.Im;
			return result;
	}

	// Absolute value member function
	float Absolute()
	{
		return sqrt(Re*Re + Im*Im);
	}
}; // ALWAYS put a semicolon at the end of struct or class
	// If it is missing, error list will tell you you're missing one in main
	// For online help: put cursor on text and click F1



// Binary times operator
// Global operator for multiplying two complex numbers together
Complex operator * (Complex a, Complex b) 
{
	Complex result;
		result.Re = (a.Re * b.Re) + (a.Im * b.Im);
		result.Im = (a.Im * b.Re) + (a.Re * b.Im);
		return result;
}