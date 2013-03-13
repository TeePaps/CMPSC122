// main.cpp - Vector class test program
// Written by Ted Papaioannou

#include <iostream>
#include <string>

using namespace std;

#define MAX_SIZE	20

void main()
{
	/*string myString = "whatever";
	cin >> myString;
	cout << myString;

	myString = myString + myString;
	char c = myString[12];
	int length = myString.length();
	cout << endl << myString.substr (4,4) << endl;*/

	// ASCII C-string - read-only string
	char myOtherString[] = "whatever";

	cin >> myOtherString;

	myOtherString[0]++;

	// Unicode C-string
	wchar_t* myUnicodeString = L"";

	
	// 
	char* s = NULL;

	system("pause");
}