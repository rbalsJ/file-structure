#pragma once
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
#include "fixtext.h"
#include "lentext.h"
#include "deltext.h"

class Student
{
public:
	int StudentId;
	char name[21];
	char address[21];
	char date[21];
	int credit;

	Student();
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

	void setId(int m_id)
	{
		StudentId = m_id;
	}

	void setName(char* m_name)
	{
		strcpy(name, m_name);
	}

	void setAddress(char* m_address)
	{
		strcpy(address, m_address);
	}

	void setDate(char* m_date)
	{
		strcpy(date, m_date);
	}


	void setCredit(int m_credit)
	{
		credit = m_credit;
	}

	void increCredit(int input)
	{
		credit = credit + input;
	}
};

//Student::Student()
//{
//	StudentId = 0;
//	name[0] = 0; address[0] = 0; date[0] = 0;
//	credit = 0;
//}