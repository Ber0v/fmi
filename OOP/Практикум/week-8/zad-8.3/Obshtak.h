#pragma once
#include "Student.h"
class Obshtak
{
public:
	Obshtak();
	Obshtak(int room, int block);
	Obshtak(const Obshtak& other);
	Obshtak& operator=(const Obshtak& other);
	~Obshtak();

	bool kickStudent(unsigned id);
	void printInfo() const;
	bool hasRoom() const;

	//getter
	int getRoom() const;
	int getBlock() const;

	//setter
	void setRoom(int room);
	void setBlock(int block);

private:
	bool addStudent(Student& student);
	void free();

private:
	int room;
	int block;
	Student* students[3];
	int count;
};