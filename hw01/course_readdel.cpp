// D.5 readdel.cpp => writedel.cpp
// read a stream of persons with delimited fields
#include <fstream>
#include <string.h>
#include "courseRegisteration.h"
#include <iostream>

using namespace std;
//Fig 4.4 extraction operator from stream file for reading delimited fields into a person object
istream & operator >> (istream & stream, CourseRegisteration& p)
{ // read fields from file
	char delim;
	stream.getline(p.name, 30,'|');
	if (strlen(p.name)==0) return stream;
	stream.getline(p.CourseId, 20, '|');
	stream >> p.StudentId; stream.ignore();
	stream >> p.credit; stream.ignore();
	stream >> p.grade; stream.ignore();
	cout << endl<<"istream.getline(object, size, '|') ½ÇÇàµÊ" << endl;
	return stream;
}
ostream& operator << (ostream& stream, CourseRegisteration& p)
{ // insert fields into file
	cout << "Person °´Ã¼¸¦ Ãâ·ÂÇÑ´Ù" << endl;
	stream << p.name << '|' << p.CourseId << '|' << p.StudentId << '|'
		<< p.credit << '|' << p.grade << '|';
	cout << endl;
	return stream;
}
int main(){

	char filename [20];
	CourseRegisteration p;
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
