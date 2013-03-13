// Circle.h - Circle class declaration
// Written by Ted Papaioannou

#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include "Shape.h"
using namespace std;

// Circle is a subclass of Shape (derived calss of Shpae; same as child class)
class Triangle : public Shape
{
public:
	// MUST call the constructor for the base class
	Triangle(int x, int y, float xB, float yB, float xC, float yC, Colors color) : Shape (x, y, color)
	{
		X = x; // equivalent to PointA.x
		Y = y; // equivalent to PointA.y
		XB = xB;
		YB = yB;
		XC = xC;
		YC = yC;
	}

	virtual void Move(int deltaX, int deltaY) //: Shape (int deltaX, int deltaY)
	{
		X += deltaX;
		Y += deltaY;
		XB += deltaX;
		YC += deltaY;
		XC += deltaX;
		YC += deltaY;
	}

	// Overloaded pure virtual function
	virtual void Scale(float scaleFactor)
	{
		XB *= scaleFactor;
		YB *= scaleFactor;
		XC *= scaleFactor;
		YC *= scaleFactor;
	}

	double GetLength(float xOne, float yOne, float xTwo, float yTwo) const
	{
		// return distance length using distance formula
		return ( sqrt(pow(yTwo - yOne, 2) + pow(xTwo - yTwo, 2)) );
	}

	virtual void Draw() const
	{
		cout << "TRIANGLE with side length AB,BC, and CA of " << GetLength(X, Y, XB, YB) << ", " <<
			GetLength(XB, YB, XC, YC) << ", and " << GetLength(XC, YC, X, Y) << " with point A at (" <<
			X <<  ", " << Y << ") and color " << GetColor() << endl << endl;
	}

private:
	float XB, YB, XC, YC;
};