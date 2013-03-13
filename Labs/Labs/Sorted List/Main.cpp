#include <iostream>
#include <vector>
#include <string>
#define NUMBER_OF_NAMES	5
using namespace std;

template<typename DATA_TYPE>
// Find the index of ‘value’ in sorted ‘myVector’. Returns NOT_FOUND when the value is not there
int BinarySearch(const vector<DATA_TYPE>& myVector, const DATA_TYPE& value,
   int startPos, int length)
{
   // Base case: empty vector?
   if ( length == 0 )
      return startPos; 
   // Base case: only one element in the vector?
   if ( length == 1 )
      if (myVector[startPos] >= value )
         return startPos; // value found! return it’s position within the vector
      else
         return startPos+1; // value not found

   // Is the element in the middle larger than the value we are looking for?
   if (myVector[startPos + length/2] > value )
      // Yes, so recursively BinarySearch the lower half of the vector
      return BinarySearch(myVector, value, startPos, length/2);
   else
      // No, so recursively BinarySearch the upper half of the vector
      return BinarySearch(myVector, value, startPos + length/2, length - length/2);
}


void main ()
{
	vector<string> names;
	vector<string>::iterator it;
	string name;
	int pos;

	cout << "Please enter 5 names to be sorted in a list: ";
	for ( int i = 0; i < NUMBER_OF_NAMES; i++ )
	{
		cin >> name;
		pos = BinarySearch(names, name, 0, i);
		it = names.begin();
		it = it + pos;
		names.insert(it, name);
	}

	for ( int i = 0; i < NUMBER_OF_NAMES; i++ )
		cout << endl << names[i];
	cout << endl;

	system("pause");
}

