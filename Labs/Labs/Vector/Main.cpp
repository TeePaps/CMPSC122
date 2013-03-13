// main.cpp - Vector class test program
// Writte by Max I. Fomitchev-Zamilov

#include <iostream>
#include <iomanip>
#include "Vector.h"
#define TEST_SIZE	10

using namespace std;

template<typename DATA_TYPE>
void PassByValueTest(Vector<DATA_TYPE> passedByValue)
{
}

template<typename DATA_TYPE>
void testAdd (Vector<DATA_TYPE>& vectorToAddTo)
{
	int size = TEST_SIZE;
	for ( int i = 0; i < size; i++ )
	{
		vectorToAddTo.Add(i + 1);
		cout << vectorToAddTo[i] << " ";
	}
	cout << endl;
}

template<typename DATA_TYPE>
void testInsert (Vector<DATA_TYPE>& vectorToInsertInto, int index, DATA_TYPE value)
{
	int size = TEST_SIZE;
	vectorToInsertInto.Insert(index, value);
	for ( int i = 0; i < size+1; i++ )
		cout << vectorToInsertInto[i] << " ";
	cout << endl;
}

template<typename DATA_TYPE>
void testRemove (Vector<DATA_TYPE>& vectorToRemoveFrom, int index)
{
	int size = TEST_SIZE;
	vectorToRemoveFrom.Remove(index);
	for ( int i = 0; i < size; i++ )
		cout << vectorToRemoveFrom[i] << " ";
	cout << endl;
}



void main()
{
	// Using the default constructor, which according to our
	// definition will create a vector of INITIAL_CAPACITY elements
	Vector<int> myVector;
	Vector<int> mySecondVector;

	// Tests copy-consrtructor
	PassByValueTest(myVector);
	// Tests 4 functions
	testAdd(myVector);
	testInsert(myVector, 5, 123);
	testRemove(myVector, 4);
	try
	{
		cout << myVector[3] << endl;
	}
	catch (char* error)
	{
		cout << "Exception occured. " << error << endl << endl;
	}

	// Tests copy-consrtructor
	PassByValueTest(mySecondVector);
	// Tests 4 functions
	testAdd(mySecondVector);
	testInsert(mySecondVector, 6, 74);
	testRemove(mySecondVector, 9);
	try {
		cout << myVector[3] << endl;
	}
	catch (char* error)
	{
		cout << "Exception occured. " << error << endl << endl;
	}

	system("pause");
}