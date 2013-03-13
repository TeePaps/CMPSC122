// Circle.h - Circle class declaration
// Written by Ted Papaioannou

#pragma once

#include <iostream>
#include <string>
#include "Shape.h"
using namespace std;

// Circle is a subclass of Shape (derived calss of Shpae; same as child class)
class Circle: public Shape
{
public:
	// MUST call the constructor for the base class
	Circle(int x, int y, int radius, Colors color) : Shape (x, y, color)
	{
		Radius = radius;
	}

	// virtual Move() is inherited without modification

	// Overloaded pure virtual function
	virtual void Scale(float scaleFactor)
	{
		Radius = int(Radius*scaleFactor);
	}

	virtual void Draw() const
	{
		cout << "CIRCLE of radius " << Radius << " with the origin at (" <<
			X <<  ", " << Y << ") and color " << GetColor() << endl << endl;
	}

private:
	int Radius;
};