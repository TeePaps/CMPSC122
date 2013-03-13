// LocalPart.h - Email local part validation class declaration
// Written by Ted Papaioannou

#pragma once

#include "String.h"
//using namespace std;

class LocalPart
{
public:
	// Required by Email class
	LocalPart() {}
	
	// Sets the Address
	void Set(const String& address);

	bool IsValid();

private:
	String Address;
};