#pragma once

struct Student
{
	char* name;
	unsigned year;
	float grade;
};

void copyString(char*& dest, const char* src);
void freeStudent(Student& s);
void printStudent(const Student& s);

void writeStudents(const char* fileName, const Student* students, int n);
Student* readStudents(const char* fileName, int& n);