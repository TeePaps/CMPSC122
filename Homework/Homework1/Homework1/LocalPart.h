// LocalPart.h - Email local part validation class declaration
// Written by Ted Papaioannou

#pragma once

#include <string>
using namespace std;

class LocalPart
{
public:
	// Required by Email class
	LocalPart() {}
	
	// Sets the Address
	void Set(const string& address);

	bool IsValid();

private:
	string Address;
};