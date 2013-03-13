// TldPart.h - Email TLD validation class declaration
// Written by Max I. Fomitchev-Zamilov

#pragma once

#include <string>
#include <fstream>
#define VALIDTLD_FILE "ValidTLDs.txt"
using namespace std;

class TldPart
{
public:
	// Required by Domain class
	TldPart() {}
	
	// Sets the Address
	void Set(const string& address);

	bool IsValid();

private:
	string Address;
};