// TldPart.cpp - Email TLD validation class implementation
// Written by Max I. Fomitchev-Zamilov

#include "TldPart.h"

void TldPart::Set(const string& address)
{
	Address = address;

	// Make Address all uppercase to match ValidTlds.txt file
	for ( int i = 0; i < Address.length(); i++)
		if ( (Address[i] >= 'a') && (Address[i] <= 'z') )
			// Subtract 32 from ASCII value to get uppercase
			Address[i] = Address[i]-32;
}

// Implements TLD validation rules
bool TldPart::IsValid()
{
	string Tld;

	// Open ValidTLD.txt file
	ifstream input(VALIDTLD_FILE);

	// match Address against the file

	// 2. Check for valid characters
	//Address.find_first_not_of();

	// 3. Check the dot rule

	// 4. Check dash rule

	// 1. Check against the list of ICAN domains
	do
	{
		input >> Tld;
		// Validate the Tld
	} while ( (!input.eof()) && (Tld != Address) );

	return !input.eof();
}

