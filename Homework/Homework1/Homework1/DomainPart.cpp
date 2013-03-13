// DomainPart.cpp - Email domain validation class implementation
// Written by Max I. Fomitchev-Zamilov

#include "DomainPart.h"

void DomainPart::Set(const string& address)
{
	Address = address;
}

// Calls IsValid() for each Subdomain
bool DomainPart::SubdomainsAreValid()
{
	for ( unsigned int i = 0; i < Subdomains.GetSize(); i++ )
		if ( !Subdomains[i].IsValid() )
			return false;

	return true;
}

// Implements domain validation rules
bool DomainPart::IsValid()
{
	return
		// Parses Address into Subdomains and Tld
		Parse() &&
		SubdomainsAreValid() &&
		Tld.IsValid();
}

// Parses Address into Subdomains and Tld
bool DomainPart::Parse()
{
	int length = Address.length();
	int index = 0;
	int newStartPoint = 0;
	int substringLength = 0;
	string substring;

	// Find '.'
	for ( int i = 0; i < length; i++ )
	{
		if ( Address[i] == '.' )
		{
			// extract a substring corresponding to subdomain
			// and store in a vector of Subdomains
			substring = Address.substr(newStartPoint, substringLength);
			Subdomains.Insert(0, SubdomainPart(substring)); // insert at head
			substringLength = 0;
			newStartPoint = i + 1;
		}
		else
			substringLength++;

	}

	// The last subdomain is actually a TLD so it needs to be stored
	// in a Tld data member
	substring = Address.substr(newStartPoint, substringLength);
	Tld.Set(substring);
	return true;
}
