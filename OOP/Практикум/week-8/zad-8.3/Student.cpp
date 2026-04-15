#pragma warning(disable:4996)

#include <iostream>
#include <cstring>
#include "Student.h"
#include "Obshtak.h"

unsigned Student::counter = 0;
Student::Student()
	:Student(nullptr, 2000, 2)
{
}

Student::Student(const char* name, unsigned year, float grade)
	:id(counter++), name(nullptr)
{
	setName(name);
	setYear(year);
	setGrade(grade);
}

Student::Student(const Student& other)
	:name(nullptr), grade(other.grade), year(other.year), id(counter++)
{
	setName(other.name);
}

Student& Student::operator=(const Student& other)
{
	if (&other == this) return *this;

	Student temp(other);
	std::swap(name, temp.name);
	std::swap(year, temp.year);
	std::swap(grade, temp.grade);

	return *this;
}

Student::~Student()
{
	delete[] name;
}


void Student::setName(const char* name)
{
	int len = strlen(name);
	if (len >= 32 && !name)
	{
		throw std::exception("Name is too long :)");
	}

	char* temp = new char[len + 1];
	strcpy(temp, name);

	delete[] this->name;
	this->name = temp;
}

unsigned Student::getId() const
{
	return id;
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

void Student::setObshtak(Obshtak* obshtak)
{
	this->obshtak = obshtak;
}

float Student::getGrade() const
{
	return grade;
}

void Student::printStudent() const
{
	std::cout << "id: " << this->id;
	std::cout << "\nname: " << this->name;
	std::cout << "\nyear: " << this->year;
	std::cout << "\ngrade: " << this->grade;
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

const Obshtak* Student::getObshtak() const
{
	return obshtak;
}

void Student::leaveObshtak()
{
	if (obshtak)
	{
		obshtak->kickStudent(id);
	}
}