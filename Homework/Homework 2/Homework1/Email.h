// Email.h - Email address validation class declaration
// Written by Max I. Fomitchev-Zamilov

#pragma once

#include "String.h"
#include "LocalPart.h"
#include "DomainPart.h"

//using namespace std;

class Email
{
public:
	Email(const char* address);

	bool IsValid();

	// Parses the Address into Local and Domain
	bool Parse();

private:
	String Address;
	// Default constructors are required to initialize Local and Domain
	LocalPart Local;
	DomainPart Domain;
};