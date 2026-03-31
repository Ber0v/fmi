#include <iostream>
#include "Time.h"

Time::Time()
{
	second = 0;
	minutes = 0;
	hour = 0;
}

void Time::PrintTime() const
{
	if (hour < 10) std::cout << '0';
	std::cout << hour << ':';

	if (minutes < 10) std::cout << '0';
	std::cout << minutes << ':';

	if (second < 10) std::cout << '0';
	std::cout << second;
}

void Time::NextSecond()
{
	second++;
	if (second >= 60)
	{
		second = 0;
		NextMinutes();
	}
}

void Time::NextMinutes()
{
	minutes++;
	if (minutes >= 60)
	{
		minutes = 0;
		NextHour();
	}
}

void Time::NextHour()
{
	hour++;
	if (hour >= 24) hour = 0;
}

bool Time::isItNightTime() const
{
	return hour >= 21 || hour <= 5;
}

short Time::getSecond() const
{
	return second;
}

short Time::getMinutes() const
{
	return minutes;
}

short Time::getHour() const
{
	return hour;
}

void Time::setSecond(short s)
{
	if (s < 60)second = s;
	else std::cout << "Invalid second\n";
}

void Time::setMinutes(short m)
{
	if (m < 60)minutes = m;
	else std::cout << "Invalid minutes\n";
}

void Time::setHour(short h)
{
	if (h < 24)hour = h;
	else std::cout << "Invalid hour\n";
}