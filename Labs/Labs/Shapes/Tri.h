// Circle.h - Circle class declaration
// Written by Ted Papaioannou

#pragma once

#include <iostream>
#include <c.math>
#include "Shape.h"

// Subclass of Shape
class Triangle : public Shape
{
public:
	Triangle(int xOne, int yOne, int xTwo, int yTwo, int xThree, int yThree Colors color) : Shape(x, y, color)
	{
		XOne = xOne;
		YOne = yOnel
		XTwo = xTwo;
		XTwo = yTwo;
		XThree = xThree;
		YThree = yThree;

		LengthOne = LengthBetweenPoints(xOne, yOne, xTwo, yTwo);
		LengthTwo = LengthBetweenPoints(xTwo, yTwo, xThree, yThree);
		LengthThree = LengthBetweenPoints( xThree, yThree, xOne, yOne);
	}

	virtual void Scale(float scaleFactor)
	{
		LengthOne = LengthOne * scaleFactor;
		LengthTwo = LengthTwo * scaleFactor;
		LengthOne = LengthTwo * scaleFactor;

		= int(Width*scaleFactor);
		Height = int(Height*scaleFactor);
	}

	virtual void Draw() const
	{
		cout << "RECTANGLE of width " << Width << " and height " << Height <<
			" with the top left corner at (" << X <<  ", " << Y << " and color " << 
			GetColor() << endl;
	}

private:

	int LengthOne, LengthTwo, LengthThree;

	int XOne, YOne;
	int XTwo, YTwo;
	int Xthree, YThree;	

	int LengthBetweenPoints(int xOne, int yOne, int xTwo, int yTwo)
	{
		return ( sqrt(pow(xTwo - xOne, 2) + pow(yTwo - yOne, 2)) )
	}
};