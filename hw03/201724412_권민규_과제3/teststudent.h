#pragma once
// Student.h
// Copyright 1997, Gregory A. Riccardi

#include <iostream>
#include "fixfld.h"
#include "length.h"
#include "delim.h"
using namespace std;
// Tip) ����ȯ
// int -> char*		: snprintf(����� ����, ������ ����, "%d", int ��);
// float -> char*	: snprintf(����� ����, ������ ����, "%f", float ��);
// char* -> int		: atoi(����)
// char* -> float	: atof(����)

class Student
{
public:
	// fields
	int StudentId;
	char Name[21];
	char Address[21];
	char Date[21];
	int Credit;
	//operations
	Student();
	void Clear();
	static int InitBuffer(DelimFieldBuffer&);
	static int InitBuffer(LengthFieldBuffer&);
	static int InitBuffer(FixedFieldBuffer&);
	int Unpack(IOBuffer &);
	int Pack(IOBuffer &) const;
	void Print(ostream&, char* label = 0) const;
	//friend istream& operator>>(istream & stream, Student & p);
	//friend ostream& operator<<(ostream & stream, Student & p);
};
