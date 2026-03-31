#include <iostream>
#include "Date.h"

Date::Date()
{
	day = 1;
	month = 1;
	year = 1970;
}

void Date::PrintDate() const
{
	std::cout << '(' << day << '.' << month << '.' << year << ')';
}

void Date::nextDay()
{
	day++;

	if (day > 31)
	{
		day = 1;
		nextMonth();
	}
}

void Date::nextMonth()
{
	month++;

	if (month > 12)
	{
		month = 1;
		nextYear();
	}
}

void Date::nextYear()
{
	year++;
}

bool Date::isSummerVacation() const
{
	return month >= 6 && month <= 9;
}

short Date::getDay() const
{
	return day;
}

short Date::getMonth() const
{
	return month;
}

int Date::getYear() const
{
	return year;
}

void Date::setDay(int d)
{
	if (d >= 1 && d <= 31)
	{
		day = d;
	}
	else
	{
		std::cout << "Invalid day\n";
	}
}

void Date::setMonth(int m)
{
	if (m >= 1 && m <= 12)
	{
		month = m;
	}
	else
	{
		std::cout << "Invalid month\n";
	}
}

void Date::setYear(int y)
{
	year = y;
}
