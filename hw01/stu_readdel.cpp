// D.5 readdel.cpp => writedel.cpp
// read a stream of persons with delimited fields
#include <fstream>
#include <string.h>
#include "student.h"
#include <iostream>

using namespace std;
//Fig 4.4 extraction operator from stream file for reading delimited fields into a person object
istream & operator >> (istream & stream, Student & p)
{ // read fields from file
	char delim;
	stream.getline(p.name, 30,'|');
	if (strlen(p.name)==0) return stream; 
	stream >> p.StudentId; stream.ignore();
	stream.getline(p.address,30,'|');
	stream.getline(p.date, 30,'|');
	stream >> p.credit; stream.ignore();
	cout << endl<<"istream.getline(object, size, '|') ½ÇÇàµÊ" << endl;
	return stream;
}
ostream& operator << (ostream& stream, Student& p)
{ // insert fields into file
	cout << "Person °´Ã¼¸¦ Ãâ·ÂÇÑ´Ù" << endl;
	stream << p.name << '|' << p.StudentId << '|' << p.address << '|'
		<< p.date << '|' << p.credit << '|';
	cout << endl;
	return stream;
}
int main(){

	char filename [20];
	Student p;
	cout << "Enter the file name:"<<flush;
	cin.getline(filename, 19);
	ifstream file (filename, ios::in);
	if (file.fail()) {
		cout << "File open failed!" <<endl;
		return 0;
	}
	while (1) {
		// read fields of person
		file >> p;
		if (strlen(p.name)==0) break;
		// write person to file
		cout << p;
	}
	system("pause");
	return 1;
}
