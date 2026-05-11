#pragma once
#include "Vehicle.h"

class Car : public Vehicle
{
public:
	Car(const char* mark, unsigned year, unsigned maxSpeed, const char* model = "NoModel", unsigned power = 0);
	Car(const Car& other);
	Car& operator=(const Car& other);
	~Car();

	bool canGoOntheHighway() const;

	const char* getModel() const { return model; }
	unsigned getPower() const { return power; }

	void setModel(const char* model);

private:
	char* model;
	unsigned power;
};