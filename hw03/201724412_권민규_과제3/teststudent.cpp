//Student.cc
#include "teststudent.h"

Student::Student() { Clear(); }

void Student::Clear()
{
	StudentId = 0;
	Name[0] = 0;
	Address[0] = 0;
	Date[0] = 0;
	Credit = 0;
}

int Student::Pack(IOBuffer & Buffer) const
{// pack the fields into a FixedFieldBuffer, 
 // return TRUE if all succeed, FALSE o/w
	int numBytes;
	char tempId[30];
	snprintf(tempId, 30, "%d", StudentId);

	char tempCred[30];
	snprintf(tempCred, 30, "%d", Credit);

	Buffer.Clear();
	numBytes = Buffer.Pack(Name);//동적 바인딩
	if (numBytes == -1) return FALSE;
	numBytes = Buffer.Pack(tempId);
	if (numBytes == -1) return FALSE;
	numBytes = Buffer.Pack(Address);
	if (numBytes == -1) return FALSE;
	numBytes = Buffer.Pack(Date);
	if (numBytes == -1) return FALSE;
	numBytes = Buffer.Pack(tempCred);
	if (numBytes == -1) return FALSE;

	return TRUE;
}

int Student::Unpack(IOBuffer & Buffer)
{
	Clear();
	int numBytes;
	char tempId[30];
	sprintf(tempId, "%d", StudentId);

	char tempCred[30];
	sprintf(tempCred, "%d", Credit);


	//power of virtual functions
	numBytes = Buffer.Unpack(Name);//Unpack()에 대항 F12를 누르면 일치하는 3개 함수 존재 - 동적 바인딩
	if (numBytes == -1) return FALSE;
	Name[numBytes] = 0;
	numBytes = Buffer.Unpack(tempId);
	if (numBytes == -1) return FALSE;
	tempId[numBytes] = 0;
	numBytes = Buffer.Unpack(Address);
	if (numBytes == -1) return FALSE;
	Address[numBytes] = 0;
	numBytes = Buffer.Unpack(Date);
	if (numBytes == -1) return FALSE;
	Date[numBytes] = 0;
	numBytes = Buffer.Unpack(tempCred);
	if (numBytes == -1) return FALSE;
	tempCred[numBytes] = 0;
	return TRUE;
}

int Student::InitBuffer(FixedFieldBuffer& Buffer)
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

int Student::InitBuffer(DelimFieldBuffer& Buffer)
// initialize a DelimFieldBuffer to be used for Persons
{
	return TRUE;
}

int Student::InitBuffer(LengthFieldBuffer& Buffer)
// initialize a LengthFieldBuffer to be used for Persons
{
	return TRUE;
}


void Student::Print(ostream & stream, char * label) const
{
	if (label == 0) stream << "Person:";
	else stream << label;
	stream << "\n\t  Name '" << Name << "'\n"
		<< "\t Student ID '" << StudentId << "'\n"
		<< "\t    Address '" << Address << "'\n"
		<< "\t       Date '" << Date << "'\n"
		<< "\t     Credit '" << Credit << "'\n" << std::flush;
}