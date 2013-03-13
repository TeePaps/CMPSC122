// Shape.h - shape abstract base class declaration
// Written by Ted Papaioannou

#pragma once
#include <iostream>
#include <string>
using namespace std;

enum Colors {Red, Green, Blue, Black, White};

// Abstract base class, because it has at least one pure virtual function
class Shape
{
public:
	Shape(int x, int y, Colors color)
	{
		X = x;
		Y = y;
		Color = color;
	}

	// virtual means the function CAN be overridden by a derived class
	virtual void Move(int deltaX, int deltaY)
	{
		X += deltaX;
		Y += deltaY;
	}

	// = 0 means it is a 'pure virtual' function,
	// it MUST be overriden by a derived class
	virtual void Scale(float scale) = 0;

	string GetColor() const
	{
		switch ( Color )
		{
		case Red:
			return "Red";
		case Blue:
			return "Blue";
		case Green:
			return "Green";
		case Black:
			return "Black";
		case White:
			return "White";
		default:
			throw "Unknown color";
		}
	}

	virtual void Draw() const = 0;

// protected is similar to private for outside-of-the-class access,
// which, however, does not impact a derived class
protected:
	int X, Y;
	Colors Color;
};