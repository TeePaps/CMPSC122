// Test 1
// Written by Ted Papaioannou

#include <iostream>
#include "Reverser.h"
#define SIZE	10

using namespace std;

void main()
{
	int arrayToReadInto [SIZE];

	cout << "Please input 10 integers:";
	for ( int i = 0; i < SIZE; i++)
		cin >> arrayToReadInto[i];
	
	Reverser<int> reversedArray(arrayToReadInto, SIZE);

	int* finalArray = reversedArray.GetReverse();

	cout << "This is that array reversed: ";
	for ( int i = 0; i < SIZE; i++)
		cout << finalArray[i] << " ";
	cout << endl;


	system("pause");
}