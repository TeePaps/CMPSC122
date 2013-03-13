// Circle.h - Circle class declaration
// Written by Ted Papaioannou

#pragma once

#include <iostream>
#include "Shape.h"

// Subclass of Shape
class Rectangle : public Shape
{
public:
	Rectangle(int x, int y, int width, int height, Colors color) : Shape(x, y, color)
	{
		Width = width;
		Height = height;
	}

	virtual void Scale(float scaleFactor)
	{
		Width = int(Width*scaleFactor);
		Height = int(Height*scaleFactor);
	}

	virtual void Draw() const
	{
		cout << "RECTANGLE of width " << Width << " and height " << Height <<
			" with the top left corner at (" << X <<  ", " << Y << ") and color " << 
			GetColor() << endl << endl;
	}

private:
	int Width, Height;
};