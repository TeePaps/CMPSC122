#include <iostream>
#include <vector>
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

using namespace std;

void main()
{
	// Container to store circles
	// pointer to base class can represent pointer to derived class
	vector<Shape*> shapes;

	// Populate the container
	Circle* myCircle = new Circle(10, 10, 100, Red);
	shapes.push_back(myCircle);

	// Create new unnamed stack-allocated instance of Circle and push_back() to vector
	shapes.push_back(new Circle(10, 10, 100, White));
	shapes.push_back(new Circle(1, 2, 3, Green));

	// Populate with rectangle
	shapes.push_back(new Rectangle(1, 2, 3, 4, Black));
	shapes.push_back(new Rectangle(5, 3, 3, 4, White));
	shapes.push_back(new Rectangle(2, 7, 10, 5, Green));


	// Populate with triangle
	shapes.push_back(new Triangle(1, 1, 3, 4, 7, 8, Blue));
	shapes.push_back(new Triangle(3, 4, 1, 5, 8, 2, Green));
	shapes.push_back(new Triangle(5, 2, 15, 2, 4, 6, Red));


	for ( unsigned int i = 0; i < shapes.size(); i++ )
	// Try...catch is only necessary in this one loop. 
	// Error will first be caught here and no other errors can
	// be further caused after the intial draw
	try
	{
		shapes[i]->Draw();
	}
	catch (char* error)
	{
		cout << "Error occured: " << error << endl;

	}

	for ( unsigned int i = 0; i < shapes.size(); i++ )
		shapes[i]->Move(1, 2);

	for ( unsigned int i = 0; i < shapes.size(); i++ )
		shapes[i]->Scale(2.0f);

	for ( unsigned int i = 0; i < shapes.size(); i++ )
		shapes[i]->Draw();

	for ( unsigned int i = 0; i < shapes.size(); i++ )
		delete shapes[i];

	system("pause");
}