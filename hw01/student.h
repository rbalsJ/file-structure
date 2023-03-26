#pragma once
#include <string.h>

class Student
{
public:
	int StudentId;
	char name[20];
	char address[20];
	char date[20];
	int credit;

	Student();
	friend std::istream& operator >> (std::istream& stream, Student& p);
	friend std::ostream& operator << (std::ostream& stream, Student& p);

	void setId(int m_id)
	{
		StudentId = m_id;
	}

	void setName(char* m_name)
	{
		strcpy(name, m_name);
	}

	void setAddress(char* m_address)
	{
		strcpy(address, m_address);
	}

	void setDate(char* m_date)
	{
		strcpy(date, m_date);
	}


	void setCredit(int m_credit)
	{
		credit = m_credit;
	}

	void increCredit(int input)
	{
		credit = credit + input;
	}
};

Student::Student()
{
	StudentId = 0;
	name[0] = 0; address[0] = 0; date[0] = 0;
	credit = 0;
}