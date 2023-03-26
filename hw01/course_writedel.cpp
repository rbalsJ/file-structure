// writedel.cpp => readdel.cpp
// write a stream of persons, using fstream.h 
/*
istream::getline
istream& getline(char*s, streamsize n);//�Է� stream ���� ���� ���ڸ� �о�鿩 s�� �����Ѵ�. delimiter�� '\n'�� ����Ѵ�.
istream& getline(char*s, streamsize n, char delim);//delimiter�� ��Ÿ�� ������ �а� �ȴ�. delimiter�� delim ���� ���޵ȴ�.
*/
#include <iostream>
#include <fstream>
#include "courseRegisteration.h"
using namespace std;
// Figure 4.1 => 2�� �ҽ��ڵ�� �ǽ�
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
