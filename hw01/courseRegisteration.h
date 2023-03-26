#pragma once
#include <string.h>

class CourseRegisteration
{
public:

	char name[20];
	char CourseId[20];
	int StudentId;
	int credit;
	float grade;

	CourseRegisteration();
	friend std::istream& operator >> (std::istream& stream, CourseRegisteration& p);
	friend std::ostream& operator << (std::ostream& stream, CourseRegisteration& p);
};

CourseRegisteration::CourseRegisteration()
{
	name[0] = 0; CourseId[0] = 0; 
	StudentId = 0; credit = 0; grade = 0;
}