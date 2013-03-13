// main.cpp - Vector class test program
// Writte by Max I. Fomitchev-Zamilov

#include <iostream>
#include "Vector.h"

using namespace std;

template<typename DATA_TYPE>
void PassByValueTest(Vector<DATA_TYPE> passedByValue)
{
}

#define TEST_SIZE	10

void main()
{
	// Using the default constructor, which according to our
	// definition will create a vector of INITIAL_CAPACITY elements
	Vector<int> myVector;

	// Setup a test vector
	for ( int i = 0; i < TEST_SIZE; i++ )
		myVector.Add(i + 1);

	// Tests copy-consrtructor
	PassByValueTest(myVector);

	// Here we use the init-constructor to create a vector of 100 elements
	Vector<int> myOtherVector(100);

	// Tests assignment operator
	myVector = myOtherVector;

	system("pause");
}