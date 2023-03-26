// writedel.cpp => readdel.cpp
// write a stream of persons, using fstream.h 
/*
istream::getline
istream& getline(char*s, streamsize n);//입력 stream 으로 부터 문자를 읽어들여 s에 저장한다. delimiter를 '\n'를 사용한다.
istream& getline(char*s, streamsize n, char delim);//delimiter가 나타날 때까지 읽게 된다. delimiter는 delim 으로 전달된다.
*/
#include <iostream>
#include <fstream>
#include "courseRegisteration.h"
using namespace std;
// Figure 4.1 => 2장 소스코드로 실습
ostream & operator << (ostream & stream, CourseRegisteration& p)
{ // insert fields into file
	stream << p.name << '|' << p.CourseId << '|'
		<< p.StudentId << '|' << p.credit << '|'
		<< p.grade << '|';
	return stream;
}
istream& operator >> (istream& stream, CourseRegisteration& p)
{ // read fields from input
	cout << "Enter name, or <cr> to end: " << flush;
	stream.getline(p.name, 30);
	if (strlen(p.name) == 0) return stream;
	cout << "Enter Course ID: " << flush; stream.getline(p.CourseId, 20);
	cout << "Enter Student ID: " << flush; stream >> p.StudentId; stream.ignore();
	cout << "Enter credit hours: " << flush; stream >> p.credit; stream.ignore();
	cout << "Enter grade : " << flush; stream >> p.grade; stream.ignore();
	return stream;
}
int main (void){
	char filename [20];
	CourseRegisteration p;
	cout << "Enter the file name:"<<flush;
	cin.getline(filename, 19);
	ofstream file (filename, ios::out);
	if (file.fail()) {
		cout << "File open failed!" <<endl;
		return 0;
	}
	while (1) {
		// read fields of person
		cin >> p;
		if (strlen(p.name)==0) break;
		// write person to file
		file << p;
	}
	system("pause");
	return 1;
}
