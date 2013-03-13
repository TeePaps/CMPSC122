// main.cpp - Email validation program main entry point
// Written by Ted Papaioannou

#include <iostream>
#include <string>
#include <fstream>
#include "String.h"
#include "Email.h"

using namespace std;

#define INPUT_FILE	"Email.txt"
#define OUTPUT_FILE	"Result.txt"

void main()
{
	cout << "Welcome to email validation program!" << endl;

	// Open files
	ifstream input(INPUT_FILE);
	ofstream output(OUTPUT_FILE);

	cout << "Reading " << INPUT_FILE << " file..." << endl;

	// Check to see if files are good
	if (input.bad())
		cout << "Error reading file" << endl;
	else
	{
		// While we are not at the end of the input file
		while ( !input.eof() )
		{
			string emailAddress;

			// Read email address from the input file
			//input >> emailAddress;

			// >> operator reads until space or until the end of line, therefore
			// we should use the getline() to avoid the space problem
			getline(input, emailAddress);

			// Object to validate email addresses
			Email email(emailAddress.c_str());

			// Validate the email address
			bool isValid = email.IsValid();

			// Write the result to the output file
			output << isValid << endl;
		}
	}

	system("pause");
}