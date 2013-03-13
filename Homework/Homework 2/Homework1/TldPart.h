// TldPart.h - Email TLD validation class declaration
// Written by Ted Papaioannou

#pragma once

#include "String.h"
#include "SubdomainPart.h"
#include <fstream>
#include <string>
#include <map>
#define VALIDTLD_FILE "ValidTLDs.txt"
using namespace std;

class TldPart : public SubdomainPart
{
public:
	// Required by Domain class
	TldPart() : SubdomainPart() {}

	TldPart(const String& address);
	
	// Sets the Address
	//void Set(const String& address);

	// Reads TLDs from a file into a map
	void PreloadTlds();

	virtual bool IsValid();

private:
	map<String, bool> TldsFromFile;
};