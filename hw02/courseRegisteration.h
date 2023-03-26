#pragma once
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
#include "fixtext.h"
#include "lentext.h"
#include "deltext.h"

class CourseRegisteration
{
public:

	char name[20];
	char CourseId[20];
	int StudentId;
	int credit;
	float grade;

	CourseRegisteration();
	void Clear();
	static int InitBuffer(FixedTextBuffer&);
	int Unpack(FixedTextBuffer&);
	int Pack(FixedTextBuffer&) const;
	static int InitBuffer(LengthTextBuffer&);
	int Unpack(LengthTextBuffer&);
	int Pack(LengthTextBuffer&) const;
	static int InitBuffer(DelimTextBuffer&);
	int Unpack(DelimTextBuffer&);
	int Pack(DelimTextBuffer&) const;
	void Print(std::ostream&);
};

//CourseRegisteration::CourseRegisteration()
//{
//	name[0] = 0; CourseId[0] = 0; 
//	StudentId = 0; credit = 0; grade = 0;
//}