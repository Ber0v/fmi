#include "User.h"

User::User()
	:name("NoName"), points(0)
{
}

User::User(const string& name, int points)
	:name(name), points(points)
{
}

void User::printUser() const
{
	std::cout << "Name: " << name << '\n'
		<< "Points: " << points << '\n';
}

const string& User::getName() const
{
	return name;
}

int User::getPoints() const
{
	return points;
}

void User::addPoints(int value)
{
	if (value <= 0)
	{
		points = 0;
		return;
	}
	else if (value <= 6)
	{
		points += ((value * 10) / 6) * 10;
	}
	else throw std::exception("problem with point");
}

void User::setName(const string& name)
{
	this->name = name;
}
