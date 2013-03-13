// SubdomainPart.h - Email subdomain validation class declaration
// Written by Max I. Fomitchev-Zamilov

#pragma once

#include <string>
using namespace std;

class SubdomainPart
{
public:
	SubdomainPart();

	// Sets the Address
	SubdomainPart(const string& address);

	bool IsValid();

private:
	string Address;
};