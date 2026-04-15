#include "Obshtak.h"
#include <iostream>

Obshtak::Obshtak()
	:room(0), block(0)
{
}

Obshtak::Obshtak(int room, int block)
	:room(room), block(block)
{
}

Obshtak::Obshtak(const Obshtak& other)
	: room(other.room), block(other.block)
{
	free();
}

Obshtak& Obshtak::operator=(const Obshtak& other)
{
	if (&other == this) return *this;

	Obshtak temp(other);
	std::swap(room, temp.room);
	std::swap(block, temp.block);

	return *this;
}

Obshtak::~Obshtak()
{
	free();
}

bool Obshtak::kickStudent(unsigned id)
{
	for (int i = 0; i < count; i++)
	{
		if (students[i]->getId() == id)
		{
			students[i]->setObshtak(nullptr);

			for (int j = i; j < count - 1; j++)
			{
				students[j] = students[j + 1];
			}

			students[count - 1] = nullptr;
			count--;

			return true;
		}
	}
	return false;
}

void Obshtak::printInfo() const
{
	std::cout << "Block: " << block << '\n';
	std::cout << "Room: " << room << '\n';
	std::cout << "Students inside: " << count << '\n';

	for (int i = 0; i < count; i++)
	{
		students[i]->printStudent();
		std::cout << '\n';
	}
}

bool Obshtak::hasRoom() const
{
	return count < 3;
}

int Obshtak::getRoom() const
{
	return room;
}

int Obshtak::getBlock() const
{
	return block;
}

void Obshtak::setRoom(int room)
{
	if (room < 0)
	{
		this->room = 0;
		return;
	}
	this->room = room;
}

void Obshtak::setBlock(int block)
{
	if (block < 0)
	{
		this->block = 0;
		return;
	}
	this->block = block;
}

bool Obshtak::addStudent(Student& student)
{
	if (!hasRoom()) return false;

	if (student.getObshtak() != nullptr) return false;

	students[count] = &student;
	count++;

	student.setObshtak(this);

	return true;
}

void Obshtak::free()
{
	count = 0;
	students[0] = students[1] = students[2] = nullptr;
}