#pragma once

class Obshtak;

class Student
{
public:
	Student();
	Student(const char* name, unsigned year, float grade);
	Student(const Student& st);
	Student& operator=(const Student& other);
	~Student();

	void printStudent() const;
	bool canGetScolarship(float minGrade)const;
	int getYearInUni(unsigned currYear)const;

	const Obshtak* getObshtak() const;
	void leaveObshtak();

	unsigned getId() const;
	const char* getName() const;
	unsigned getYear() const;
	float getGrade() const;

	void setName(const char* name);
	void setYear(unsigned year);
	void setGrade(float grade);

private:
	static unsigned counter;

	const unsigned id;
	char* name;
	unsigned year;  //birthYear
	float grade;

	Obshtak* obshtak;

	void setObshtak(Obshtak* obshtak);

	friend class Obshtak;
};