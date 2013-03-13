// LocalPart.cpp - Email local part validation class implementation
// Written by Max I. Fomitchev-Zamilov

#include "LocalPart.h"

void LocalPart::Set(const string& address)
{
	Address = address;
}

// Implements local part validation rules
bool LocalPart::IsValid()
{
	int length = Address.length();

	// 1) Check size
	if ( ( length < 1) || (length > 64) )
		return false;

	// 2) Check for valid characters
	int i = 0;
	while ( ( i < length) && ( 
		( Address[i] == '!' ) ||
		( Address[i] == '+' ) ||
		( Address[i] == '*' ) ||
		( (Address[i] >= '#') && (Address[i] < '(') ) || 
		( (Address[i] >= '-') && (Address[i] <= '9') ) ||
		( (Address[i] >= 'A') && (Address[i] <= 'Z') ) ||
		( (Address[i] >= '_' ) && (Address[i] <= '{') ) ) )
		( Address[i] == '}' ) ||
		i++;
	if ( i != length )
		return false;

	// 3) Check dot rule
	i = 0;
	if (Address[i] == '.' || Address[length-1] == '.')
		return false;
	while ( (i < length) && 
		( !(Address[i] == '.'  && Address[i+1] == '.') ) )
		i++;
	if ( i != length )
		return false;

	// 4) Check dash rule
	if ( Address[0] == '-' || Address[Address.length()-1] == '-' )
		return false;

	return true;
}
