// Vector.h -Vector template calss declaration
// Written by Ted Papaioannou

#pragma once
#include <iostream>

#define INITIAL_CAPACITY	20
#define CAPACITY_BOOST	10

// Encapsulates a C-array
template<typename DATA_TYPE>
class Reverser
{
public:
	// Default / init-consructor hybrid, creates a zero-sized vector
	// with non-zero intiial capacity
	Reverser(const DATA_TYPE* sourceData, int sourceSize)
	{
		Size = sourceSize;

		// Allocate the C-array elements
		Data = new DATA_TYPE[Size];

		// Copy C-Arry in reverse order
		for ( int i = sourceSize-1; i >= 0; i-- )
			Data[(sourceSize-1)-i] = sourceData[i];
	}

    DATA_TYPE* GetReverse()
	{ 
        return Data;
    }

    ~Reverser(){
        delete[] Data;
    }

private:
	// The count of actual C-array elements used
	int Size;
	// the encapsulated C-array
	DATA_TYPE* Data;
};