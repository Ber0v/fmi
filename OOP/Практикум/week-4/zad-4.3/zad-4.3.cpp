#include <iostream>
#include "students.h"

using namespace std;

int main()
{
	int n;
	cin >> n;

	Student* students = new (nothrow) Student[n];

	if (students == nullptr)
	{
		cout << "Allocation error";
		return -1;
	}

	for (int i = 0; i < n; i++)
	{
		students[i].name = nullptr;
	}

	char buffer[1024];

	for (int i = 0; i < n; i++)
	{
		cin >> buffer;
		copyString(students[i].name, buffer);
		cin >> students[i].year >> students[i].grade;
	}

	writeStudents("students.dat", students, n);

	int readCount = 0;
	Student* loadedStudents = readStudents("students.dat", readCount);

	if (loadedStudents != nullptr)
	{
		for (int i = 0; i < readCount; i++)
		{
			printStudent(loadedStudents[i]);
		}

		for (int i = 0; i < readCount; i++)
		{
			freeStudent(loadedStudents[i]);
		}
		delete[] loadedStudents;
	}

	for (int i = 0; i < n; i++)
	{
		freeStudent(students[i]);
	}
	delete[] students;
}