#pragma once
// Student.h
// Copyright 1997, Gregory A. Riccardi

#include <iostream>
#include "fixfld.h"
#include "length.h"
#include "delim.h"
using namespace std;
// Tip) 형변환
// int -> char*		: snprintf(저장될 변수, 버퍼의 길이, "%d", int 값);
// float -> char*	: snprintf(저장될 변수, 버퍼의 길이, "%f", float 값);
// char* -> int		: atoi(변수)
// char* -> float	: atof(변수)

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
