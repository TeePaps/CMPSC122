// Main.cpp - Email Validation program (Homework 1)
// Written by Ted Papaioannou

#include <iostream>
#include <fstream>
#include <string>
#

using namespace std;

#define INPUT_FILE "Email.txt"
#define OUTPUT_FILE "Result.txt"

void main ()
{
	cout << "Welcome to email validation program!" << endl;

	// Open input and output file
	ifstream input(INPUT_FILE);
	ofstream output(OUTPUT_FILE);

	cout << "Reading file " << INPUT_FILE << "..." << endl;

	// use bad() function to check if input file is good
	INPUT_FILE.bad()

	// Read emails until you reach the end of the input file
	// output email you read for sake of validation
	while ( !input.eof() )
	{
		string emailAddress;
		//input >> emailAddress;
		// Must read the entire line such that we do not get only the first word
		// when there is a space and we are using the >> operator
		getline(input, emailAddress);

		// Create an instance of the email validation class
		Email email(emailAddress);

		// Validate the email address
		bool isValid;

		output << isValid << endl;
	}
	system ("pause");
}