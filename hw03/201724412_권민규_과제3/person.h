#pragma once
// F.1 person.h Definition for class person

#include <iostream>
#include "fixfld.h"
#include "length.h"
#include "delim.h"
using namespace std;

class Person
{
public:
	// fields
	char LastName[11];
	char FirstName[11];
	char Address[16];
	char City[16];
	char State[3];
	char ZipCode[10];
	int age = 0;
	//operations
	Person();
	static int InitBuffer(DelimFieldBuffer&);
	static int InitBuffer(LengthFieldBuffer&);
	static int InitBuffer(FixedFieldBuffer&);
	void Clear();
	int Unpack(IOBuffer&);
	int Pack(IOBuffer&) const;
	void Print(ostream&, char* label = 0) const;
};