// Email.cpp - Email address validation class implementation
// Written by Max I. Fomitchev-Zamilov

#include "Email.h"

Email::Email(const string& address)
{
	Address = address;
}

bool Email::IsValid()
{
	return
		// Parses the Address into Local and Domain
		Parse() &&
		Local.IsValid() &&
		Domain.IsValid();
}

// Parses the Address into Local and Domain
bool Email::Parse()
{
	// 1) Search for '@', return false if not found
	int found = Address.find('@');
	if ( found == -1 )
		return false;

	// 2) Extract a substring corresponding to local part (before '@')
	Local.Set(Address.substr(0, found));

	// 3) Extract a substring corresponding to domain (after '@')
	Domain.Set(Address.substr(found+1));
	return true;
}