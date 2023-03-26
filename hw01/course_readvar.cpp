// D.6 readvar.cpp
// write a stream of persons, using fstream.h 
#include <fstream>
#include <iostream>
#include <strstream>
#include <string.h>
#include "courseRegisteration.h"
using namespace std;
istream & operator >> (istream & stream, CourseRegisteration& p)
{ // read fields from stream
	char delim;
	stream.getline(p.name, 30,'|');
	if (strlen(p.name)==0) return stream; 
	stream.getline(p.CourseId, 20, '|');
	stream >> p.StudentId; stream.ignore();
	stream >> p.credit; stream.ignore();
	stream >> p.grade; stream.ignore();
	return stream;
}

//Fig 4.9 - read a variable-sized Person record
int ReadVariablePerson (istream & stream, CourseRegisteration& p)
{ // read a variable sized record from stream and store it in p
  // if read fails, set p.LastName to empty string and return 0
	short length;
	//istream& read(const char*, streamsize);
	stream . read ((char*)&length, sizeof(length)); //stream.read(&length, sizeof(length)) => 오류
	cout << "length = " << length << endl;
	if (stream . fail()){p.name[0]=0; return 0;}
	char * buffer = new char[length+1];
	stream . read (buffer, length);
	buffer [length] = 0; // terminate buffer with null
	istrstream strbuff (buffer);
	strbuff >> p;
	return 1;
}
ostream& operator << (ostream& stream, CourseRegisteration& p)
{ // insert fields into file
	cout << "Person 객체를 출력한다" << endl;
	stream << p.name << '|' << p.CourseId << '|'
		<< p.StudentId << '|' << p.credit << '|'
		<< p.grade << '|';
	cout << endl;
	return stream;
}
int main (void){
	char filename [20];
	CourseRegisteration p;
	cout << "Enter the file name:"<<flush;
	cin.getline(filename, 19);
	ifstream stream (filename, ios::in);
	if (stream.fail()) {
		cout << "File open failed!" <<endl;
		return 0;
	}
	while (1) {
		// read fields of person
		ReadVariablePerson (stream, p);
		if (strlen(p.name)==0) break;
		// write person to file
		cout << p;
	}
	system("pause");
	return 1;
}
