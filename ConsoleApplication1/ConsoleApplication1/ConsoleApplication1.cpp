#include <iostream>

int main()
{
	char name[100];
	int age;
	double grade;
	std::cin >> name >> age >> grade;
	std::cout << "Name:" << name << "Age:" << age << "grade:" << grade;
}