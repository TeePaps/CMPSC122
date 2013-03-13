// SubdomainPart.cpp - Email subdomain validation class implementation
// Written by Ted Papaioannou

#include "SubdomainPart.h"
#include "LocalPart.h"

SubdomainPart::SubdomainPart() {}

SubdomainPart::SubdomainPart(const String& address)
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
