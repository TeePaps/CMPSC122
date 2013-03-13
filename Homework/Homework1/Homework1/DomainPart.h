// DomainPart.h - Email domain validation class declaration
// Written by Max I. Fomitchev-Zamilov

#pragma once

#include <string>
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
	void Set(const string& address);

	bool IsValid();

	// Parses Address into Subdomains and Tld
	bool Parse();

	bool SubdomainsAreValid();

private:
	string Address;
	Vector<SubdomainPart> Subdomains;
	TldPart Tld;
};