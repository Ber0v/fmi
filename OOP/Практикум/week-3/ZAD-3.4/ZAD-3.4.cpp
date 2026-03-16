#include <iostream>
#include <fstream>

struct Student
{
	char name[32];
	unsigned year;
	float grade;
};

void writeStudents()
{
	Student students[3] =
	{
		{"Ivan", 1, 5.50},
		{"Maria", 2, 5.80},
		{"Georgi", 3, 4.90}
	};

	std::ofstream file("students.txt");

	if (!file.is_open())
	{
		std::cout << "Error creating/finding file\n";
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		file << students[i].name << " "
			<< students[i].year << " "
			<< students[i].grade << "\n";

		if (!file)
		{
			std::cout << "Write error\n";
			return;
		}
	}

	file.close();

	std::cout << "Writing to file completed successfully\n";
}

void readStudents()
{
	Student students[3];

	std::ifstream file("students.txt");

	if (!file.is_open())
	{
		std::cout << "Error opening file\n";
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		file >> students[i].name
			>> students[i].year
			>> students[i].grade;

		if (!file)
		{
			std::cout << "Error reading\n";
			return;
		}
	}

	file.close();

	std::cout << "Students Read:\n";

	for (int i = 0; i < 3; i++)
	{
		std::cout << students[i].name << " "
			<< students[i].year << " "
			<< students[i].grade << "\n";
	}
}

int main()
{
	writeStudents();
	readStudents();
}