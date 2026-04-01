#include <iostream>
#include <cstring>
#include "Student.h"

Student::Student()
{
	strcpy(name, "NoNmae");
	year = 0;
	grade = 0;
}

Student::Student(const char* name, unsigned year, float grade)
	: year(year), grade(grade)
{
	setName(name);
}

Student::Student(const Student& st)
{
	strcpy(name, st.name);
	year = st.year;
	grade = st.grade;
}

void Student::setName(const char* name)
{
	if (strlen(name) >= 32 && !name)
	{
		std::cout << "Name is too long :)";
		return;
	}

	strcpy(this->name, name);
}

const char* Student::getName() const
{
	return name;
}

void Student::setYear(unsigned year)
{
	if (year < 1900 && year > 2026)
	{
		std::cout << "you must be lying to me";
		return;
	}
	this->year = year;
}

unsigned Student::getYear() const
{
	return year;
}

void Student::setGrade(float grade)
{
	if (grade < 0 && grade > 6)
	{
		std::cout << "you will like it";
		return;
	}
	this->grade = grade;
}

float Student::getGrade() const
{
	return grade;
}

void Student::printStudent() const
{
	std::cout << "name: " << this->name;
	std::cout << "\nyear: " << this->year;
	std::cout << "\ngrade:" << this->grade;
}

bool Student::canGetScolarship(float minGrade) const
{
	if (grade < minGrade)
		return false;

	return true;
}

int Student::getYearInUni(unsigned currYear) const
{
	return (currYear - year) - 19;
}