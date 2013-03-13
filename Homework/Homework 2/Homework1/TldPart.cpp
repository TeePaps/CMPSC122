// TldPart.cpp - Email TLD validation class implementation
// Written by Ted Papaioannou

#include "TldPart.h"

TldPart::TldPart(const String& address) : SubdomainPart(address)
{
	//Address = address;
	if ( TldsFromFile.empty() )
		PreloadTlds();

	if (Address != "")
	{
		// Make Address all uppercase to match ValidTlds.txt file
		for ( int i = 0; i < Address.GetLength(); i++)
			if ( (Address[i] >= 'a') && (Address[i] <= 'z') )
				// Subtract 32 from ASCII value to get uppercase
				Address[i] = Address[i]-32;
	}
}

void TldPart::PreloadTlds()
{
	string Tld;
	String myString;
	ifstream input(VALIDTLD_FILE);
	if ( TldsFromFile.empty() )
	{
		do 
		{
			input >> Tld;
			//TldsFromFile.insert(pair<String, bool>(Tld.c_str(), true) );
			myString = Tld.c_str();
			TldsFromFile[myString] = 1;
		}
		while ( !input.eof() );
	}
}

// Implements TLD validation rules
bool TldPart::IsValid()
{
	// Open ValidTLD.txt file

	// match Address against the file

	// 2. Check for valid characters
	//Address.find_first_not_of();

	// 3. Check the dot rule

	// 4. Check dash rule

	// 1. Check against the list of ICAN domains
	return TldsFromFile[Address];
}

