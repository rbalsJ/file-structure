#include <fstream>
#include <iomanip>
#include "iobuffer.h"
#include "fixfld.h"
#include "length.h"
#include "testCourse.h"
#include "buffile.h"
#include <iostream>
using namespace std;

int N = 0;
CourseRegisteration* course = new CourseRegisteration[N];

template <class IOB>
void testBuffer(IOB& Buff, char* myfile)
{
	int result;
	int* recaddr = new int[N];

	// Test writing
	//Buff . Print (cout);
	BufferFile TestOut(Buff);
	result = TestOut.Create(myfile, ios::in | ios::out);
	cout << "create file " << result << endl;
	if (!result)
	{
		cout << "Unable to create file " << myfile << endl;
		result = TestOut.Open(myfile, ios::in | ios::out);
		cout << "open file " << result << endl;
		if (!result)
		{
			cout << "Unable to open file " << myfile << endl;
			return;
		}
	}

	for (int i = 0; i < N; i++)
	{
		course[i].Pack(Buff);
		recaddr[i] = TestOut.Write();
		cout << "write at" << recaddr[i] << endl;
	}
	TestOut.Close();

	// test reading
	BufferFile TestIn(Buff);
	TestIn.Open(myfile, ios::in);
	//result = TestIn . ReadHeader ();
	//cout <<"read header "<<result<<endl;
	for (int i = 0; i < N; i++)
	{
		TestIn.Read(recaddr[i]);
		course[i].Unpack(Buff);
		course[i].Print(cout, "record: ");
	}

	result = TestIn.Read(recaddr[N] * 2);
	if (result != -1) cout << "Read past end of file! Error." << endl;
	else cout << "Read past end of file failed! Correct." << endl;
}

void InitPerson()
{
	cout << "The number of Course object records : ";
	cin >> N;
	cin.clear();
	cin.ignore(INT_MAX, '\n');

	for (int i = 0; i < N; i++)
	{
		cout << "Enter Student name : ";
		cin.getline(course[i].Name, 21);
		cout << "Enter Student ID : ";
		cin >> course[i].CourseId;
		cout << "Enter Student Address : ";
		cin >> course[i].StudentId;
		cout << "Enter date of enrollment : ";
		cin >> course[i].Credit;
		cout << "Enter credit hours : ";
		cin >> course[i].Grade;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
}

void testFixedField()
{
	cout << "Testing Fixed Field Buffer" << endl;
	FixedFieldBuffer Buff(5);
	CourseRegisteration::InitBuffer(Buff);
	testBuffer(Buff, "fixfile.dat");
}

void testLength()
{
	cout << "\nTesting LengthTextBuffer" << endl;
	LengthFieldBuffer Buff;
	CourseRegisteration::InitBuffer(Buff);
	testBuffer(Buff, "lenfile.dat");
}

void testDelim()
{
	cout << "\nTesting DelimTextBuffer" << endl;
	DelimFieldBuffer::SetDefaultDelim('|');
	DelimFieldBuffer Buff;
	CourseRegisteration::InitBuffer(Buff);
	testBuffer(Buff, "delfile.dat");
}

int main(int argc, char** argv)
{
	InitPerson();
	//testFixedField ();
	//testLength ();
	testDelim();

	return 0;
}
