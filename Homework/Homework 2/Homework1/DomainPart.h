// DomainPart.h - Email domain validation class declaration
// Written by Ted Papaioannou

#pragma once

#include "String.h"
#include "Vector.h"
#include "SubdomainPart.h"
#include "TldPart.h"
using namespace std;

class DomainPart
{
public:
	// Required by Email class
	DomainPart() {}
	
	// Sets the Address
	void Set(const String& address);

	bool IsValid();

	// Parses Address into Subdomains and Tld
	bool Parse();

	bool SubdomainsAreValid();

private:
	String Address;
	Vector<SubdomainPart*> Subdomains;
	TldPart Tld;
};