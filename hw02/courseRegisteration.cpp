//person.cpp
// Copyright 1997, Gregory A. Riccardi

#include "courseRegisteration.h"

CourseRegisteration::CourseRegisteration()
{
	Clear ();
}

void CourseRegisteration::Clear ()
{
	// set each field to an empty string
	name[0] = 0;
	CourseId[0] = 0;
	StudentId = 0;
	credit = 0;
	grade = 0.0;
	
}

int CourseRegisteration::Pack (FixedTextBuffer & Buffer) const
{// pack the fields into a FixedTextBuffer, return TRUE if all succeed, FALSE o/w
	int result;
	string tempId = to_string(StudentId);
	char const* Id = tempId.c_str();
	string tempCredit = to_string(credit);
	char const* cred = tempCredit.c_str();
	string tempGrade = to_string(grade);
	char const* Cgrade = tempGrade.c_str();

	Buffer . Clear ();
	result = Buffer . Pack (name);
	result = result && Buffer . Pack (CourseId);
	result = result && Buffer . Pack (Id);
	result = result && Buffer . Pack (cred);
	result = result && Buffer . Pack (Cgrade);
	return result;
}

int CourseRegisteration::Unpack (FixedTextBuffer & Buffer)
{
	Clear ();
	int result;
	string tempId = to_string(StudentId);
	char* Id = new char[tempId.size() + 1];
	copy(tempId.begin(), tempId.end(), Id); Id[tempId.size()] = '\0';

	string tempCredit = to_string(credit);
	char* cred = new char[tempCredit.size() + 1];
	copy(tempCredit.begin(), tempCredit.end(), cred); cred[tempCredit.size()] = '\0';

	string tempGrade = to_string(grade);
	char* Cgrade = new char[tempGrade.size() + 1];
	copy(tempGrade.begin(), tempGrade.end(), Cgrade); Cgrade[tempGrade.size()] = '\0';

	result = Buffer . Unpack (name);
	result = result && Buffer . Unpack (CourseId);
	result = result && Buffer . Unpack (Id);
	result = result && Buffer . Unpack (cred);
	result = result && Buffer . Unpack (Cgrade);

	return result;
}

int CourseRegisteration::InitBuffer (FixedTextBuffer & Buffer)
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

int CourseRegisteration::Pack (LengthTextBuffer & Buffer) const
{// pack the fields into a FixedTextBuffer, return TRUE if all succeed, FALSE o/w
	int result;
	string tempId = to_string(StudentId);
	char const* Id = tempId.c_str();
	string tempCredit = to_string(credit);
	char const* cred = tempCredit.c_str();
	string tempGrade = to_string(grade);
	char const* Cgrade = tempGrade.c_str();

	Buffer.Clear();
	result = Buffer.Pack(name);
	result = result && Buffer.Pack(CourseId);
	result = result && Buffer.Pack(Id);
	result = result && Buffer.Pack(cred);
	result = result && Buffer.Pack(Cgrade);
	return result;
}

int CourseRegisteration::Unpack (LengthTextBuffer & Buffer)
{
	int result;
	string tempId = to_string(StudentId);
	char* Id = new char[tempId.size() + 1];
	copy(tempId.begin(), tempId.end(), Id); Id[tempId.size()] = '\0';

	string tempCredit = to_string(credit);
	char* cred = new char[tempCredit.size() + 1];
	copy(tempCredit.begin(), tempCredit.end(), cred); cred[tempCredit.size()] = '\0';

	string tempGrade = to_string(grade);
	char* Cgrade = new char[tempGrade.size() + 1];
	copy(tempGrade.begin(), tempGrade.end(), Cgrade); Cgrade[tempGrade.size()] = '\0';

	result = Buffer.Unpack(name);
	result = result && Buffer.Unpack(CourseId);
	result = result && Buffer.Unpack(Id);
	result = result && Buffer.Unpack(cred);
	result = result && Buffer.Unpack(Cgrade);
	return result;
}

int CourseRegisteration::InitBuffer (LengthTextBuffer & Buffer)
// initialize a LengthTextBuffer to be used for Persons
{
	return TRUE;
}

int CourseRegisteration::Pack (DelimTextBuffer & Buffer) const
{// pack the fields into a FixedTextBuffer, return TRUE if all succeed, FALSE o/w
	int result;
	string tempId = to_string(StudentId);
	char const* Id = tempId.c_str();
	string tempCredit = to_string(credit);
	char const* cred = tempCredit.c_str();
	string tempGrade = to_string(grade);
	char const* Cgrade = tempGrade.c_str();

	Buffer . Clear ();
	result = Buffer.Pack(name);
	result = result && Buffer.Pack(CourseId);
	result = result && Buffer.Pack(Id);
	result = result && Buffer.Pack(cred);
	result = result && Buffer.Pack(Cgrade);
	return result;
}

int CourseRegisteration::Unpack (DelimTextBuffer & Buffer)
{
	int result;
	string tempId = to_string(StudentId);
	char* Id = new char[tempId.size() + 1];
	copy(tempId.begin(), tempId.end(), Id); Id[tempId.size()] = '\0';

	string tempCredit = to_string(credit);
	char* cred = new char[tempCredit.size() + 1];
	copy(tempCredit.begin(), tempCredit.end(), cred); cred[tempCredit.size()] = '\0';

	string tempGrade = to_string(grade);
	char* Cgrade = new char[tempGrade.size() + 1];
	copy(tempGrade.begin(), tempGrade.end(), Cgrade); Cgrade[tempGrade.size()] = '\0';

	result = Buffer.Unpack(name);
	result = result && Buffer.Unpack(CourseId);
	result = result && Buffer.Unpack(Id);
	result = result && Buffer.Unpack(cred);
	result = result && Buffer.Unpack(Cgrade);
	return result;
}

int CourseRegisteration::InitBuffer (DelimTextBuffer & Buffer)
// initialize a DelimTextBuffer to be used for Persons
{
	return TRUE;
}

void CourseRegisteration::Print (std::ostream & stream)
{
	stream << "Student:" <<"      Name '"<<name<<"'\n"
		<< "\t Course ID '"<<CourseId<<"'\n"
		<< "\t Student ID'"<<StudentId<<"'\n"
		<< "\t    Credit '"<<credit<<"'\n"
		<< "\t     Grade '"<<grade<<"'\n" << std::flush;
}



