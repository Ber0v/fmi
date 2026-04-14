#pragma once

class Student
{
public:
	Student();
	Student(const char* name, unsigned year, float grade);
	Student(const Student& st);
	Student& operator=(const Student& other);
	~Student();

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
	static unsigned counter;

	const unsigned id;
	char* name;
	unsigned year;  //birthYear
	float grade;
};