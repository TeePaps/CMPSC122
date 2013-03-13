
/*
Double-linked list
#include <list>
list<string> myList;

size() returns count of elements in the list;
push_front() adds an item at the head of the list;
push_back() adds an item  at the end of the list;
pop_front() removes an item from the head of the list;
pop_back() removes an item from the end of the list;
insert() inserts an item at a specified iterator position;
erase() removes an item at specified iterator position;
begin() returns iterator position of the first item in the list;
end() returns iterator position of the last element.
*/

#include <iostream>
#include <string>
#include <list>

using namespace std;

void main()
{
	list<string> myList;
	string stringToAdd;
	list<string>::iterator it;

	cout << "Type in five names to be sorted in a list: " << endl;

	for ( int i = 0; i < 5; i++ )
	{
		cout << i+1 << ". ";
		cin >> stringToAdd;
		myList.push_back(stringToAdd);

		it = myList.begin();
		string currentValue = *it;
		while ( currentValue < stringToAdd )
		{
			currentValue = *(++it);
		}
		myList.insert(it, stringToAdd);
		myList.pop_back();

	}

	cout << endl << "The sorted list is now: " << endl;
	int placeNumber = 1;
	// pos is an iterator for myList
	for ( list<string>::iterator pos = myList.begin(); pos != myList.end(); pos++ )
	{
		// Retrieve current element by dereferencing pos
		string currentValue = *pos;
		cout << placeNumber++ << ". " << currentValue << endl;
	}

	system ("pause");

}
