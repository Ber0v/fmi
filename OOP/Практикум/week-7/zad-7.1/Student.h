#pragma once

class Student
{
public:
	Student();
	Student(const char* name, unsigned year, float grade);
	Student(const Student& st);

	void setName(const char* name);
	const char* getName() const;
	void setYear(unsigned year);
	unsigned getYear() const;
	void setGrade(float grade);
	float getGrade() const;
	void printStudent() const;
	bool canGetScolarship(float minGrade)const;
	int getYearInUni(unsigned currYear)const;

private:
	char name[32];
	unsigned year;  //birthYear
	float grade;
};