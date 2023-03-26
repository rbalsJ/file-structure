// D.7 writestr.cpp - 가변길이 레코드 + 가변길이 필드
// write a stream of persons, using fstream.h 
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include "student.h"
using namespace std;

//Fig 4.7 write a variable-length, delimited buffer to a file
const int MaxBufferSize = 200;
int WritePerson (ostream & stream, Student & p)
{
	string tempId = to_string(p.StudentId);
	char const* Id = tempId.c_str();
	string tempCredit = to_string(p.credit);
	char const* credit = tempCredit.c_str();

	char buffer [MaxBufferSize];
	strcpy(buffer, p.name); strcat(buffer,"|");
	strcat(buffer, Id); strcat(buffer, "|");
	strcat(buffer, p.address);  strcat(buffer,"|");
	strcat(buffer, p.date);  strcat(buffer,"|");
	strcat(buffer, credit); strcat(buffer, "|");
	short length=strlen(buffer); 
	stream.write ((char *)&length, sizeof(length)); // write length
	stream.write (&buffer[0], length);
	return 1;
}
istream& operator >> (istream& stream, Student& p)
{ // read fields from input
	cout << "Enter name, or <cr> to end: " << flush;
	stream.getline(p.name, 30);
	if (strlen(p.name) == 0) return stream;
	cout << "Enter Student ID: " << flush; stream >> p.StudentId; stream.ignore();
	cout << "Enter address: " << flush; stream.getline(p.address, 30);
	cout << "Enter date of enrollment: " << flush; stream.getline(p.date, 30);
	cout << "Enter credit hours: " << flush; stream >> p.credit; stream.ignore();
	return stream;
}
int main (void){
	char filename [20];
	Student p;
	cout << "Enter the file name:"<<flush;
	cin.getline(filename, 19);
	ofstream stream (filename, ios::out);
	if (stream.fail()) {
		cout << "File open failed!" <<endl;
		return 0;
	}
	while (1) {
		// read fields of person
		cin >> p;
		if (strlen(p.name)==0) break;
		// write person to output stream
		WritePerson(stream,p);
	}
	system("pause");
	return 1;
}

