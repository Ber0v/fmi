#include "Bicycle.h"

Bicycle::Bicycle(const char* mark, unsigned year, unsigned maxSpeed, unsigned speeds, bool haveBell)
	:Vehicle(mark, year, maxSpeed), numberOfSpeeds(speeds), haveBell(haveBell)
{
}

bool Bicycle::isNew() const
{
	return getYear() > 2016;
}