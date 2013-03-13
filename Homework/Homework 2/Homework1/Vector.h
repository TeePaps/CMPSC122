// Vector.h -Vector template calss declaration
// Written by Ted Papaioannou

#pragma once
#include <iostream>

#define INITIAL_CAPACITY	20
#define CAPACITY_BOOST	10

// Encapsulates a C-array
template<typename DATA_TYPE>
class Vector
{
public:
	// Default / init-consructor hybrid, creates a zero-sized vector
	// with non-zero intiial capacity
	Vector(int initialCapacity = INITIAL_CAPACITY)
	{
		Size = 0;
		Capacity = initialCapacity; 

		// Allocate the C-array elements
		Data = new DATA_TYPE[Capacity];
	}

	// MUST HAVE a copy-constructor that performs deep copy
	Vector(const Vector& copyFrom)
	{
		// Necessary to prevent the delete[] Data; statement in the assignment
		// operator from freezing because Data has some garbage address in it
		Data = NULL;

		// Call the assignment operator to perform the deep copy
		*this = copyFrom;
	}

	// Destructor: MUST HAVE because we allocate memory
	// called implicitly (automatically) in 2 situations:
	// 1. When your object goes out of scope
	// 2. When you delete
	~Vector()
	{
		delete[] Data;
	}

	// MUST HAVE an assignment operator that performs deep copy
	Vector& operator = (const Vector& copyFrom)
	{
		// 0) Dispose of the old C-array
		delete[] Data;

		// 1) Copy Size and Capacity
		Size = copyFrom.Size;
		Capacity = copyFrom.Capacity;

		// 2) Alloacte memory
		Data = new DATA_TYPE[Capacity];

		// 3) Copy the Vector elements
		for ( int i = 0; i < Size; i++ )
			Data[i] = copyFrom.Data[i];

		// ALWAYS RETURN *this
		return *this;
	}

	// Index operator
	DATA_TYPE& operator [] (int index) const
	{
		// Check bounds and throw the exception
		if ( (index < 0) || (index > Size) )
			throw "Vector::operator []: Index out of bounds";

		return Data[index];
	}

	// Accessor functions: read-only access to Size and Capacity
	int GetSize() const
	{
		return Size;
	}
	int GetCapacity()
	{
		return Capacity;
	}

	void Add(const DATA_TYPE& newElement)
	{
		Insert(Size, newElement);
	}

	void Insert(int index, const DATA_TYPE& insertValue)
		// Must move the tail; Add is a special case of this
		// May need to reallocate vector
	{
	
		// 1. Boost the Capacity
		Capacity += CAPACITY_BOOST;
		// 2. Allocate new vector of larger capactiy
		DATA_TYPE* newData = new DATA_TYPE[Capacity];

		// 3. Copy from the old C-array into the new C-array
		try
		{
			for ( int i = 0; i < Size+1; i++ )
				{
					if (i < index)
						newData[i] = Data[i];
					else if (i == index)
						newData[i] = insertValue;
					else
						newData[i] = Data[i-1];
				}
		}
		catch(char* error)
		{
			cout << "Exception occured. " << error << endl << endl;
		}

		// 4. Dispose of the old C-array
		delete[] Data;

		// 5. Re-assign the pointer
		Data = newData;

		Size++;

	}

	void Remove(int index)
		// EXTRA CREDIT: deallocate memory after
	{	
		try
		{
			for ( int i = index; i < Size-1; i++ )
				Data[i] = Data[i+1];
			Data[Size-1] = NULL;

		}
		catch (char* error)
		{
			cout << "Exception occured. " << error << endl << endl;
		}

		// Dispose of the old C-array
		// delete Data[Size-1];

		Size--;
	}

private:
	// The count of actual C-array elements used
	int Size;
	// The count of C-array elements allocated
	int Capacity;
	// the encapsulated C-array
	DATA_TYPE* Data;
};