#include "Car.h"
#include <cstring>
#include <stdexcept>

Car::Car(const char* mark, unsigned year, unsigned maxSpeed, const char* model, unsigned power)
	:Vehicle(mark, year, maxSpeed), model(nullptr), power(power)
{
	setModel(model);
}

Car::Car(const Car& other)
	: Vehicle(other), model(nullptr), power(other.power)
{
	setModel(other.model);
}

Car& Car::operator=(const Car& other)
{
	if (&other == this) return *this;
	Car temp(other);

	Vehicle::operator=(temp);

	std::swap(model, temp.model);
	std::swap(power, temp.power);

	return *this;
}

Car::~Car()
{
	delete[] model;
	model = nullptr;
}

bool Car::canGoOntheHighway() const
{
	return getMaxSpeed() >= 50;
}

void Car::setModel(const char* model)
{
	if (!model) throw std::invalid_argument("");
	char* temp = new char[strlen(model) + 1];
	strcpy(temp, model);

	delete[] this->model;
	this->model = temp;
}
