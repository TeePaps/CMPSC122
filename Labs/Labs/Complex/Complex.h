//unary -, ==, +, !=, +, -, *, /
//					  ^__float__^

// Complex.h - Complex type definition
// Written by Ted Papaioannou

// Complex.h - Complex type definition
// Written by Ted Papaioannou

#include <iostream>
#pragma once // EVERY header file created needs this!
// Use because you may use the same header twice
#include <cmath>

#define PI 3.14159265

// User defined type (aka class) Complex
template<typename DATA_TYPE> //<typename REAL_TYPE, typename IM_TYPE, int N> // can say just "type"
struct Complex
{
	// DATA MEMBERS
	// Real party of the complex number
	DATA_TYPE Re;
	// Imaginary part of the complex number
	DATA_TYPE Im;

	// Init-constructor (doubles as default constructor)
	Complex(DATA_TYPE real = 0.0, DATA_TYPE imaginary = 0.0 /* default argument*/)
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
	Complex complement() const
	{
		return Complex(Re, -Im);
	}

	// unary minus (negation)
	Complex operator - () const
	{
		return Complex(-Re, -Im);
	}

	Complex operator + (const Complex& right) const
	{
		return Complex(Re + right.Re, Im + right.Im);
	}

	Complex operator + (float real) const
	{
		return Complex(Re + real, Im);
	}

	// Binary minus operator
	// Global operator for subtracting two complex numbers together
	Complex operator - (const Complex& b) const
	{
		return Complex(Re - b.Re, Im - b.Im);
	}

	Complex operator - (float real) const
	{
		return Complex(Re - real, Im);
	}

	Complex operator * (const Complex& b) const
	{
		return Complex(Re * b.Re + Im * b.Im, Re * b.Im + Im * b.Re);
	}

	Complex operator * (float real) const
	{
		return Complex(Re * real, Im * real);
	}

	Complex operator / (const Complex& b) const
	{
		Complex numerator = *this * b.complement();
		DATA_TYPE divisor = b.Absolute() * b.Absolute();
		if (divisor == NULL)
		{
			// Exception
			throw "Complex::operator /: Division by zero";
		}
		return Complex(numerator.Re/divisor, numerator.Im/divisor);
	}


	Complex operator / (float real) const
	{
		if (real == 0.0f)
		{
			// Exception
			throw "Complex::operator /: Division by zero";
		}
		return Complex(Re/real, Im/real);
	}



	// Absolute value member function
	DATA_TYPE Absolute() const // Means that the function does NOT modify class data members 
	{
		return sqrt(Re*Re + Im*Im);
	}

	DATA_TYPE Phase() const
	{
		screw you;
	}

	DATA_TYPE Phasor() const
	{
		DATA_TYPE phi = atan(Im/Re)/1.0f * 180.0f/PI;
		if (Re<0 && Im < 0)
			return (phi - 180.0f);
		else if (Re<0)
			return phi + 180.0f;
		else 
			return phi;
	}

	// COMPARISON OPERATORS
	bool operator == (const Complex& compareTo) const
	{
		return 
			(Re == compareTo.Re) && (Im == compareTo.Im);
	}

	// DUPLICATION
	/*bool operator != (const Complex& compareTo) const
	{
		return 
			(Re != compareTo.Re) && (Im != compareTo.Im);
	}*/

	bool operator != (const Complex& compareTo) const
	{
		return
			!(*this == compareTo);
	}
		
}; // ALWAYS put a semicolon at the end of struct or class
	// If it is missing, error list will tell you you're missing one in main
	// For online help: put cursor on text and click F1

// GLOBAL stream output operator for class Complex
// have to use ostream in order to use cout
template<typename TYPE>
std::ostream& operator << (std::ostream& out, const Complex<TYPE>& myComplex)
{
	return
		out << myComplex.Re << " + i" << myComplex.Im;
}
