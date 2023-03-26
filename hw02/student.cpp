//person.cpp
// Copyright 1997, Gregory A. Riccardi

#include "student.h"

Student::Student()
{
	Clear ();
}

void Student::Clear ()
{
	// set each field to an empty string
	name[0] = 0;
	StudentId = 0;
	address[0] = 0;
	date[0] = 0;
	credit = 0;
	
}

int Student::Pack (FixedTextBuffer & Buffer) const
{// pack the fields into a FixedTextBuffer, return TRUE if all succeed, FALSE o/w
	int result;
	string tempId = to_string(StudentId);
	char const* Id = tempId.c_str();
	string tempCredit = to_string(credit);
	char const* cred = tempCredit.c_str();

	Buffer . Clear ();
	result = Buffer . Pack (name);
	result = result && Buffer . Pack (Id);
	result = result && Buffer . Pack (address);
	result = result && Buffer . Pack (date);
	result = result && Buffer . Pack (cred);
	return result;
}

int Student::Unpack (FixedTextBuffer & Buffer)
{
	Clear ();
	int result;
	string tempId = to_string(StudentId);
	char* Id = new char[tempId.size() + 1];
	copy(tempId.begin(), tempId.end(), Id); Id[tempId.size()] = '\0';

	string tempCredit = to_string(credit);
	char* cred = new char[tempCredit.size() + 1];
	copy(tempCredit.begin(), tempCredit.end(), cred); cred[tempCredit.size()] = '\0';

	result = Buffer . Unpack (name);
	result = result && Buffer . Unpack (Id);
	result = result && Buffer . Unpack (address);
	result = result && Buffer . Unpack (date);
	result = result && Buffer . Unpack (cred);

	return result;
}

int Student::InitBuffer (FixedTextBuffer & Buffer)
// initialize a FixedTextBuffer to be used for Persons
{
	int result;

	result = Buffer . AddField (20); // Name [10];
	result = result && Buffer . AddField (20); // studentId [15];
	result = result && Buffer . AddField (20); // Address [20];
	result = result && Buffer . AddField (20); // date [20];
	result = result && Buffer . AddField (10);  // credit [10];
	return result;
}

int Student::Pack (LengthTextBuffer & Buffer) const
{// pack the fields into a FixedTextBuffer, return TRUE if all succeed, FALSE o/w
	int result;
	string tempId = to_string(StudentId);
	char const* Id = tempId.c_str();
	string tempCredit = to_string(credit);
	char const* cred = tempCredit.c_str();

	Buffer . Clear ();
	result = Buffer . Pack (name);
	result = result && Buffer . Pack (Id);
	result = result && Buffer . Pack (address);
	result = result && Buffer . Pack (date);
	result = result && Buffer . Pack (cred);
	return result;
}

int Student::Unpack (LengthTextBuffer & Buffer)
{
	int result;
	string tempId = to_string(StudentId);
	char* Id = new char[tempId.size() + 1];
	copy(tempId.begin(), tempId.end(), Id); Id[tempId.size()] = '\0';
	string tempCredit = to_string(credit);
	char* cred = new char[tempCredit.size() + 1];
	copy(tempCredit.begin(), tempCredit.end(), cred); cred[tempCredit.size()] = '\0';

	result = Buffer . Unpack (name);
	result = result && Buffer . Unpack (Id);
	result = result && Buffer . Unpack (address);
	result = result && Buffer . Unpack (date);
	result = result && Buffer . Unpack (cred);
	return result;
}

int Student::InitBuffer (LengthTextBuffer & Buffer)
// initialize a LengthTextBuffer to be used for Persons
{
	return TRUE;
}

int Student::Pack (DelimTextBuffer & Buffer) const
{// pack the fields into a FixedTextBuffer, return TRUE if all succeed, FALSE o/w
	int result;
	string tempId = to_string(StudentId);
	char const* Id = tempId.c_str();
	string tempCredit = to_string(credit);
	char const* cred = tempCredit.c_str();

	Buffer . Clear ();
	result = Buffer . Pack (name);
	result = result && Buffer . Pack (Id);
	result = result && Buffer . Pack (address);
	result = result && Buffer . Pack (date);
	result = result && Buffer . Pack (cred);
	return result;
}

int Student::Unpack (DelimTextBuffer & Buffer)
{
	int result;
	string tempId = to_string(StudentId);
	char* Id = new char[tempId.size() + 1];
	copy(tempId.begin(), tempId.end(), Id); Id[tempId.size()] = '\0';
	string tempCredit = to_string(credit);
	char* cred = new char[tempCredit.size() + 1];
	copy(tempCredit.begin(), tempCredit.end(), cred); cred[tempCredit.size()] = '\0';

	result = Buffer . Unpack (name);
	result = result && Buffer . Unpack (Id);
	result = result && Buffer . Unpack (address);
	result = result && Buffer . Unpack (date);
	result = result && Buffer . Unpack (cred);
	return result;
}

int Student::InitBuffer (DelimTextBuffer & Buffer)
// initialize a DelimTextBuffer to be used for Persons
{
	return TRUE;
}

void Student::Print (std::ostream & stream)
{
	stream << "Student:" <<"      Name '"<<name<<"'\n"
		<< "\t Student ID'"<<StudentId<<"'\n"
		<< "\t   Address '"<<address<<"'\n"
		<< "\t      Date '"<<date<<"'\n"
		<< "\t    Credit '"<<credit<<"'\n" << std::flush;
}



