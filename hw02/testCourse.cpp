// test.cc// Copyright 1997, Gregory A. Riccardi
// 4장 과제2: while(1) { } 문을 완성한다.
#include <fstream>
#include <string.h>
#include <iomanip>
#include "fixtext.h"
#include "lentext.h"
#include "deltext.h"
#include "courseRegisteration.h"
using namespace std;
//*
int testFixText()
{
	//Student student;
	//FixedTextBuffer Buff(6);
	//Student::InitBuffer(Buff);
	//strcpy(student.name, "Ames      ");
	//strcpy(student.StudentId, "201724412      ");
	//strcpy(person.Address, "123 Maple      ");
	//strcpy(person.City, "Stillwater     ");
	//strcpy(person.State, "OK");
	//strcpy(person.ZipCode, "74075    ");
	//person.Print(cout);
	//person.Pack(Buff);
	//Buff.Print(cout);
	//ofstream TestOut("fixtext.dat", ios::out | ios::binary);
	//Buff.Write(TestOut);
	//TestOut.close();
	//ifstream TestIn("fixtext.dat", ios::in | ios::binary);
	//FixedTextBuffer InBuff(6);
	//Person::InitBuffer(InBuff);
	//Buff.Read(TestIn);
	//person.Unpack(Buff);
	//person.Print(cout);
	//Person person;
	//Person* stable[10];
	//FixedTextBuffer Buff(6);
	//Person::InitBuffer(Buff);
	//char filename[20];
	//cout << "Enter the file name:" << flush;
	//cin.getline(filename, 19);
	//*
	CourseRegisteration course[100];
	int count = 0; int select; char filename[20];

	while (1)
	{
		cout << "\nTesting FixTextBuffer" << endl;
		cout << "\nSelect command 1: record input, 2. display, 3. write to file, 4. read from file, 5: Quit => ";
		cin >> select;

		switch (select) {
		case 1:
			//to store a array of Person objects by inputing
			cout << "the number of Course object records : ";
			cin >> count;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			for (int i = 0; i < count; i++)
			{
				cout << "Enter Student name : ";
				cin.getline(course[i].name, 20);
				cout << "Enter Course ID : ";
				cin.getline(course[i].CourseId, 20);
				cout << "Enter Student ID : ";
				cin >> course[i].StudentId;
				cout << "Enter credit hours : ";
				cin >> course[i].credit;
				cout << "Enter grade : ";
				cin >> course[i].grade;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
			break;
		case 2:
			// to display the array of Person objects into screen
			for (int i = 0; i < count; i++)
			{
				course[i].Print(cout);
			}
			break;
		case 3:
		{
			// to write the array of Person objects into a file
			cout << "Enter file name: ";
			cin >> filename;
			ofstream fostream(filename, ios::out | ios::binary);
			if (fostream.fail()) {
				cout << "File open failed!" << endl;
				return 0;
			}
			FixedTextBuffer Buff(5);
			CourseRegisteration::InitBuffer(Buff);
			for (int i = 0; i < count; i++)
			{
				cout << "pack course" << course[i].Pack(Buff) << endl;
				Buff.Print(cout);
				Buff.Write(fostream);
			}
			fostream.close();
			cout << "+++++++++++++++++++++++++++++" << endl;
			break;
		}
		case 4:
		{
			// to read the array of Person records from the file
			ifstream fistream(filename, ios::in | ios::binary);
			if (fistream.fail()) {
				cout << "File open failed!" << endl;
				return 0;
			}
			FixedTextBuffer InBuff(5);
			CourseRegisteration::InitBuffer(InBuff);
			for (int i = 0; i < count; i++)
			{
				cout << "read" << InBuff.Read(fistream) << endl;
				cout << "unpack" << course[i].Unpack(InBuff) << endl;
				course[i].Print(cout);
			}
			fistream.close();
			break;
		}
		default:
			// others
			exit(0);
			break;
		}
	}
}


int testLenText()
{
	//char filename[20];
	//cout << "\nTesting LengthTextBuffer" << endl;
	//Person person;
	//LengthTextBuffer Buff;
	//Person::InitBuffer(Buff);
	//strcpy(person.LastName, "Ames");
	//strcpy(person.FirstName, "Mary");
	//strcpy(person.Address, "123 Maple");
	//strcpy(person.City, "Stillwater");
	//strcpy(person.State, "OK");
	//strcpy(person.ZipCode, "74075");
	//person.Print(cout);
	//Buff.Print(cout);
	//cout << "pack person " << person.Pack(Buff) << endl;
	//Buff.Print(cout);
	//ofstream TestOut("lentext.dat", ios::out | ios::binary);
	//Buff.Write(TestOut);
	//Buff.Write(TestOut);
	//strcpy(person.FirstName, "Dave");
	//person.Print(cout);
	//person.Pack(Buff);
	//Buff.Write(TestOut);
	//TestOut.close();
	//ifstream TestIn("lentext.dat", ios::in | ios::binary);
	//LengthTextBuffer InBuff;
	//Person::InitBuffer(InBuff);
	//cout << "read " << Buff.Read(TestIn) << endl;
	//cout << "unpack " << person.Unpack(Buff) << endl;
	//person.Print(cout);
	//cout << "read " << Buff.Read(TestIn) << endl;
	//cout << "unpack " << person.Unpack(Buff) << endl;
	//person.Print(cout);
	//cout << "read " << Buff.Read(TestIn) << endl;
	//cout << "unpack " << person.Unpack(Buff) << endl;
	//person.Print(cout);
	
	CourseRegisteration course[100];
	int count = 0; int select; char filename[20];

	while (1)
	{
		cout << "\nTesting LengthTextBuffer" << endl;
		cout << "\nSelect command 1: record input, 2. display, 3. write to file, 4. read from file, 5: Quit => ";
		cin >> select;

		switch (select) {
		case 1:
			//to store a array of Person objects by inputing
			cout << "the number of course object records : ";
			cin >> count;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			for (int i = 0; i < count; i++)
			{
				cout << "Enter Student name : ";
				cin.getline(course[i].name, 20);
				cout << "Enter Course ID : ";
				cin.getline(course[i].CourseId, 20);
				cout << "Enter Student ID : ";
				cin >> course[i].StudentId;
				cout << "Enter credit hours : ";
				cin >> course[i].credit;
				cout << "Enter grade : ";
				cin >> course[i].grade;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
			break;
		case 2:
			// to display the array of Person objects into screen
			for (int i = 0; i < count; i++)
			{
				course[i].Print(cout);
			}
			break;
		case 3:
			{
			// to write the array of Person objects into a file
			cout << "Enter file name: ";
			cin >> filename;
			ofstream fostream(filename, ios::out | ios::binary);
			if (fostream.fail()) {
				cout << "File open failed!" << endl;
				return 0;
			}
			LengthTextBuffer Buff;
			CourseRegisteration::InitBuffer(Buff);
			for (int i = 0; i < count; i++)
			{
				cout << "pack course " << course[i].Pack(Buff) << endl;
				Buff.Print(cout);
				Buff.Write(fostream);
			}
			fostream.close();
			break;
			}
		case 4:
			{
			// to read the array of Person records from the file
			ifstream fistream(filename, ios::in | ios::binary);
			if (fistream.fail()) {
				cout << "File open failed!" << endl;
				return 0;
			}
			LengthTextBuffer InBuff;
			CourseRegisteration::InitBuffer(InBuff);
			for (int i = 0; i < count; i++)
			{
				cout << "read " << InBuff.Read(fistream) << endl;
				cout << "unpack " << course[i].Unpack(InBuff) << endl;
				course[i].Print(cout);
			}
			fistream.close();
			break;
			}
		default:
			// others
			exit(0);
			break;
		}
	}
	return 1;
}

int testDelText()
{
	//char filename[20];
	//cout << "\nTesting DelimTextBuffer" << endl;
	//Student student;
	//strcpy(student.name, "Mary");
	//student.StudentId = 201724412;
	//strcpy(student.address, "123 Maple");
	//strcpy(student.date, "2022-02-28");
	//student.credit = 20;
	//student.Print(cout);
	//DelimTextBuffer Buff;
	//Student::InitBuffer(Buff);
	//Buff.Print(cout);
	//cout << "pack person " << student.Pack(Buff) << endl;
	//Buff.Print(cout);
	//ofstream TestOut("deltextperson.txt", ios::out | ios::binary | ios::trunc);
	//Buff.Write(TestOut);
	//Buff.Write(TestOut);
	//strcpy(student.name, "Dave");
	//student.Print(cout);
	//student.Pack(Buff);
	//Buff.Write(TestOut);
	//TestOut.close();
	//cout << "+++++++++++++++++++++++++++++" << endl;
	//ifstream TestIn("deltextperson.txt", ios::in | ios::binary);
	//DelimTextBuffer InBuff;	Student::InitBuffer(InBuff);
	//cout << "read " << Buff.Read(TestIn) << endl;
	//cout << "unpack " << student.Unpack(Buff) << endl;
	//student.Print(cout);
	//cout << "read " << Buff.Read(TestIn) << endl;
	//cout << "unpack " << student.Unpack(Buff) << endl;
	//student.Print(cout);
	//cout << "read " << Buff.Read(TestIn) << endl;
	//cout << "unpack " << student.Unpack(Buff) << endl;
	//student.Print(cout);
	//*
	CourseRegisteration course[100];
	int count = 0; int select; char filename[20];

	while (1)
	{
		cout << "\nTesting DelimTextBuffer" << endl;
		cout << "\nSelect command 1: record input, 2. display, 3. write to file, 4. read from file, 5: Quit => ";
		cin >> select;

		switch (select) {
		case 1:
			//to store a array of Person objects by inputing
			cout << "the number of Person object records : ";
			cin >> count;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			for (int i = 0; i < count; i++)
			{
				cout << "Enter Student name : ";
				cin.getline(course[i].name, 20);
				cout << "Enter Course ID : ";
				cin.getline(course[i].CourseId, 20);
				cout << "Enter Student ID : ";
				cin >> course[i].StudentId;
				cout << "Enter credit hours : ";
				cin >> course[i].credit;
				cout << "Enter grade : ";
				cin >> course[i].grade;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
			break;
		case 2:
			// to display the array of Person objects into screen
			for (int i = 0; i < count; i++)
				course[i].Print(cout);
			break;
		case 3:
		{
			// to write the array of Person objects into a file
			cout << "Enter file name: ";
			cin >> filename;
			ofstream fostream(filename, ios::out | ios::binary | ios::trunc);
			if (fostream.fail()) {
				cout << "File open failed!" << endl;
				return 0;
			}
			DelimTextBuffer Buff;
			CourseRegisteration::InitBuffer(Buff);
			for (int i = 0; i < count; i++)
			{
				cout << "pack person " << course[i].Pack(Buff) << endl;
				Buff.Print(cout);
				Buff.Write(fostream);
			}
			fostream.close();
			cout << "+++++++++++++++++++++++++++++" << endl;
			break;
		}
		case 4:
		{
			// to read the array of Person records from the file
			ifstream fistream(filename, ios::in | ios::binary);
			if (fistream.fail()) {
				cout << "File open failed!" << endl;
				return 0;
			}
			DelimTextBuffer InBuff;
			CourseRegisteration::InitBuffer(InBuff);
			for (int i = 0; i < count; i++)
			{
				cout << "read " << InBuff.Read(fistream) << endl;
				cout << "unpack " << course[i].Unpack(InBuff) << endl;
				course[i].Print(cout);
			}
			fistream.close();
			break;
		}
		default:
			// others
			exit(0);
			break;
		}
	}
		//*/
	return 1;
}


int main(void)
{
	//testDelText();
	testFixText();
	//testLenText();
	system("pause");
	return 1;
}
