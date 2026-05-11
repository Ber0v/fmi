#include "Vehicle.h"
#include <cstring>
#include <stdexcept>

Vehicle::Vehicle(const char* mark, unsigned year, unsigned maxSpeed)
	:mark(nullptr), year(year), maxSpeed(maxSpeed)
{
	setMark(mark);
}

Vehicle::Vehicle(const Vehicle& other)
	: Vehicle(other.mark, other.year, other.maxSpeed)
{
}

Vehicle& Vehicle::operator=(const Vehicle& other)
{
	if (&other == this) return *this;
	Vehicle temp(other);

	std::swap(mark, temp.mark);
	std::swap(year, temp.year);
	std::swap(maxSpeed, temp.maxSpeed);

	return *this;
}

Vehicle::~Vehicle()
{
	delete[] mark;
	mark = nullptr;
}

void Vehicle::setMark(const char* mark)
{
	if (!mark) throw std::invalid_argument("");
	char* temp = new char[strlen(mark) + 1];
	strcpy(temp, mark);

	delete[] this->mark;
	this->mark = temp;
}