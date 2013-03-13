// SubdomainPart.h - Email subdomain validation class declaration
// Written by Ted Papaioannou

#pragma once

#include "String.h"
using namespace std;

class SubdomainPart
{
public:
	SubdomainPart();

	// Sets the Address
	SubdomainPart(const String& address);

	virtual bool IsValid();

	//virtual void PreloadTlds() = 0;

protected:
	String Address;
};