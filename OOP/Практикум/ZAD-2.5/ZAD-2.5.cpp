#include <iostream>

enum class Specialnost
{
	UP, FPR, OOP
};

struct Student
{
	char name[32];
	int course;
	Specialnost spec;
	double avg;
};

Student createStudent()
{
	Student s;
	std::cout << "Name: ";
	std::cin >> s.name;

	std::cout << "course: ";
	std::cin >> s.course;

	std::cout << "Specialnost \n0-Up, \n1-FPR, \n2-OOP\n";
	int spec;
	std::cin >> spec;
	s.spec = (Specialnost)spec;

	std::cout << "Sreden uspeh: ";
	std::cin >> s.avg;

	return s;
}

void printStudent(const Student& s)
{
	std::cout << "Ime: " << s.name << '\n';
	std::cout << "Kurs: " << s.course << '\n';
	std::cout << "Specialnost: " << (int)s.spec << '\n';
	std::cout << "Sreden uspeh: " << s.avg << '\n';
}

double averageGrade(Student arr[], int n)
{
	double sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum += arr[i].avg;
	}

	return sum / n;
}

int main()
{
	int n;
	std::cout << "Broi studenti: ";
	std::cin >> n;

	Student students[100];

	for (int i = 0; i < n; i++)
	{
		std::cout << "Student " << i + 1 << '\n';
		students[i] = createStudent();
	}

	std::cout << '\n';

	for (int i = 0; i < n; i++)
	{
		printStudent(students[i]);
		std::cout << '\n';
	}

	std::cout << "Sreden uspeh: " << averageGrade(students, n) << '\n';

	return 0;
}