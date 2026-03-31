#include <iostream>
#include <cstring>

class Student
{
public:
	Student()
	{
		strcpy(name, "NoNmae");
		year = 0;
		grade = 0;
	}

	void setName(const char* name)
	{
		if (strlen(name) >= 32 && !name)
		{
			std::cout << "Name is too long :)";
			return;
		}

		strcpy(this->name, name);
	}

	const char* getName() const
	{
		return name;
	}

	void setYear(unsigned year)
	{
		if (year < 1900 && year > 2026)
		{
			std::cout << "you must be lying to me";
			return;
		}
		this->year = year;
	}

	unsigned getYear() const
	{
		return year;
	}

	void setGrade(float grade)
	{
		if (grade < 0 && grade > 6)
		{
			std::cout << "you will like it";
			return;
		}
		this->grade = grade;
	}

	float getGrade() const
	{
		return grade;
	}

	void printStudent() const
	{
		std::cout << "name: " << this->name;
		std::cout << "\nyear: " << this->year;
		std::cout << "\ngrade:" << this->grade;
	}

	bool canGetScolarship(float minGrade)const
	{
		if (grade < minGrade)
			return false;

		return true;
	}

	int getYearInUni(unsigned currYear)const
	{
		return (currYear - year) - 19;
	}

private:
	char name[32];
	unsigned year;  //birthYear
	float grade;
};

int main()
{
	Student st;
}