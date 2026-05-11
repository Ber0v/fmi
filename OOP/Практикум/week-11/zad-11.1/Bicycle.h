#pragma once
#include "Vehicle.h"

class Bicycle : public Vehicle
{
public:
	Bicycle(const char* mark, unsigned year, unsigned maxSpeed, unsigned speeds = 0, bool haveBell = false);

	bool isNew() const;

	unsigned getNumberOfSpeeds() const { return numberOfSpeeds; }
	bool hasBell() const { return haveBell; }

private:
	unsigned numberOfSpeeds;
	bool haveBell;
};