// Main.cpp - String class tests
// Written by Ted Papaioannou

#include <iostream>
#include "String.h"

using namespace std;

void main ()
{
String child = String("child");
String child2 = String("child");
String car = String("car");
String testString = String();


// Test = operator
// Test 1
testString = child; 
cout << testString << endl;
// Test 2
testString = car; 
cout << testString << endl;


// Test "==" operator
// Test 1
cout << (child == child2) << endl;
// Test 2
cout << (child == car) << endl; 


// Test "!=" operator
// Test 1
cout << (child != child2) << endl; 
// Test 2
cout << (child != car) << endl; 


// Test "+" operator
// Test 1
testString = child + child2;
cout << testString << endl;
// Test 2
testString = child + car;
cout << testString << endl;


// Test Find()
try
{
	// Test 1
	cout << child.Find('x', 2) << endl;
	// Test 2
	cout << testString.Find('c', 3) << endl;
	// Test 3
	cout << testString.Find('c', 20) << endl;
}
catch ( String error )
{
	cout << "Error occured: " << error << endl;
}


// Test SubString()
// Test Find()
try
{
	// Test 1
	cout << child.Substring(2, 2) << endl;
	// Test 2
	cout << testString.Substring(1, 5) << endl;
	// Test 3
	cout << testString.Substring(10, 5) << endl;
}
catch ( String error )
{
	cout << "Error occured: " << error << endl;
}


system ("pause");
}