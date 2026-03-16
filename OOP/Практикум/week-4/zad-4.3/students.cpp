#include "students.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void copyString(char*& dest, const char* src)
{
	int len = strlen(src);
	dest = new (nothrow) char[len + 1];

	if (dest == nullptr)
	{
		return;
	}

	strcpy_s(dest, len + 1, src);
}

void freeStudent(Student& s)
{
	delete[] s.name;
	s.name = nullptr;
}

void printStudent(const Student& s)
{
	cout << "Name: " << s.name << '\n';
	cout << "Year: " << s.year << '\n';
	cout << "Grade: " << s.grade << '\n';
	cout << '\n';
}

void writeStudents(const char* fileName, const Student* students, int n)
{
	ofstream file(fileName, ios::binary);

	if (!file.is_open())
	{
		cout << "File open error";
		return;
	}

	file.write((const char*)&n, sizeof(n));

	for (int i = 0; i < n; i++)
	{
		int len = strlen(students[i].name);
		file.write((const char*)&len, sizeof(len));
		file.write(students[i].name, len);
		file.write((const char*)&students[i].year, sizeof(students[i].year));
		file.write((const char*)&students[i].grade, sizeof(students[i].grade));
	}

	file.close();
}

Student* readStudents(const char* fileName, int& n)
{
	ifstream file(fileName, ios::binary);

	if (!file.is_open())
	{
		cout << "File open error";
		n = 0;
		return nullptr;
	}

	file.read((char*)&n, sizeof(n));

	Student* students = new (nothrow) Student[n];

	if (students == nullptr)
	{
		cout << "Allocation error";
		n = 0;
		return nullptr;
	}

	for (int i = 0; i < n; i++)
	{
		students[i].name = nullptr;
	}

	for (int i = 0; i < n; i++)
	{
		int len;
		file.read((char*)&len, sizeof(len));

		students[i].name = new (nothrow) char[len + 1];

		if (students[i].name == nullptr)
		{
			cout << "Allocation error";

			for (int j = 0; j < i; j++)
			{
				freeStudent(students[j]);
			}
			delete[] students;
			n = 0;
			return nullptr;
		}

		file.read(students[i].name, len);
		students[i].name[len] = '\0';

		file.read((char*)&students[i].year, sizeof(students[i].year));
		file.read((char*)&students[i].grade, sizeof(students[i].grade));
	}

	file.close();
	return students;
}