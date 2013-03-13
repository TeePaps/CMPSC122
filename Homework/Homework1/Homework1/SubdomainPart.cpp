// SubdomainPart.cpp - Email subdomain validation class implementation
// Written by Max I. Fomitchev-Zamilov

#include "SubdomainPart.h"
#include "LocalPart.h"

SubdomainPart::SubdomainPart() {}

SubdomainPart::SubdomainPart(const string& address)
{
	Address = address;
}

// Implements subdomain validation rules
bool SubdomainPart::IsValid()
{
	// Check seperate header file for this function
	LocalPart localPartSubdomain;
	localPartSubdomain.Set(Address);
	return localPartSubdomain.IsValid();
}
