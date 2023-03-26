// writedel.cpp => readdel.cpp
// write a stream of persons, using fstream.h 
/*
istream::getline
istream& getline(char*s, streamsize n);//�Է� stream ���� ���� ���ڸ� �о�鿩 s�� �����Ѵ�. delimiter�� '\n'�� ����Ѵ�.
istream& getline(char*s, streamsize n, char delim);//delimiter�� ��Ÿ�� ������ �а� �ȴ�. delimiter�� delim ���� ���޵ȴ�.
*/
#include <iostream>
#include <fstream>
#include "student.h"
using namespace std;
// Figure 4.1 => 2�� �ҽ��ڵ�� �ǽ�
ostream & operator << (ostream & stream, Student & p)
{ // insert fields into file
	stream << p.name << '|' << p.StudentId << '|'
		<< p.address << '|' << p.date << '|'
		<< p.credit << '|';
	return stream;
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
