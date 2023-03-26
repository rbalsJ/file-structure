//Student.cc
#include "testCourse.h"

CourseRegisteration::CourseRegisteration() { Clear(); }

void CourseRegisteration::Clear()
{
	Name[0] = 0;
	CourseId[0] = 0;
	StudentId = 0;
	Credit = 0;
	Grade = 0;
}

int CourseRegisteration::Pack(IOBuffer & Buffer) const
{// pack the fields into a FixedFieldBuffer, 
 // return TRUE if all succeed, FALSE o/w
	int numBytes;
	char tempId[30];
	snprintf(tempId, 30, "%d", StudentId);

	char tempCred[30];
	snprintf(tempCred, 30, "%d", Credit);

	char tempGrade[30];
	snprintf(tempGrade, 30, "%f", Grade);

	Buffer.Clear();
	numBytes = Buffer.Pack(Name);//동적 바인딩
	if (numBytes == -1) return FALSE;
	numBytes = Buffer.Pack(CourseId);
	if (numBytes == -1) return FALSE;
	numBytes = Buffer.Pack(tempId);
	if (numBytes == -1) return FALSE;
	numBytes = Buffer.Pack(tempCred);
	if (numBytes == -1) return FALSE;
	numBytes = Buffer.Pack(tempGrade);
	if (numBytes == -1) return FALSE;

	return TRUE;
}

int CourseRegisteration::Unpack(IOBuffer & Buffer)
{
	Clear();
	int numBytes;
	char tempId[30];
	snprintf(tempId, 30, "%d", StudentId);

	char tempCred[30];
	snprintf(tempCred, 30, "%d", Credit);

	char tempGrade[30];
	snprintf(tempGrade, 30, "%f", Grade);


	//power of virtual functions
	numBytes = Buffer.Unpack(Name);//Unpack()에 대항 F12를 누르면 일치하는 3개 함수 존재 - 동적 바인딩
	if (numBytes == -1) return FALSE;
	Name[numBytes] = 0;
	numBytes = Buffer.Unpack(CourseId);//Unpack()에 대항 F12를 누르면 일치하는 3개 함수 존재 - 동적 바인딩
	if (numBytes == -1) return FALSE;
	CourseId[numBytes] = 0;
	numBytes = Buffer.Unpack(tempId);
	if (numBytes == -1) return FALSE;
	tempId[numBytes] = 0;
	numBytes = Buffer.Unpack(tempCred);
	if (numBytes == -1) return FALSE;
	tempCred[numBytes] = 0;
	numBytes = Buffer.Unpack(tempGrade);
	if (numBytes == -1) return FALSE;
	tempGrade[numBytes] = 0;
	return TRUE;
}

int CourseRegisteration::InitBuffer(FixedFieldBuffer& Buffer)
// initialize a FixedFieldBuffer to be used for Persons
{
	int result;
	result = Buffer.AddField(10); // LastName [11];
	result = result && Buffer.AddField(10); // firstName [11];
	result = result && Buffer.AddField(15); // Address [16];
	result = result && Buffer.AddField(15); // City [16];
	result = result && Buffer.AddField(2); // State [3];
	result = result && Buffer.AddField(9); // ZipCode [10];
	return result;
}

int CourseRegisteration::InitBuffer(DelimFieldBuffer& Buffer)
// initialize a DelimFieldBuffer to be used for Persons
{
	return TRUE;
}

int CourseRegisteration::InitBuffer(LengthFieldBuffer& Buffer)
// initialize a LengthFieldBuffer to be used for Persons
{
	return TRUE;
}


void CourseRegisteration::Print(ostream & stream, char * label) const
{
	if (label == 0) stream << "Person:";
	else stream << label;
	stream << "\n\t  Name '" << Name << "'\n"
		<< "\t  Course ID '" << CourseId << "'\n"
		<< "\t Student ID '" << StudentId << "'\n"
		<< "\t     Credit '" << Credit << "'\n"
		<< "\t      Grade '" << Grade << "'\n" << std::flush;
}