#pragma once
#include "string.h"
class User
{
public:
	User();
	User(const string& name, int points = 0);

	//method
	void printUser() const;

	//getter
	const string& getName() const;
	int getPoints() const;

	//setter
	void addPoints(int value);

private:
	void setName(const string& name);

private:
	string name;
	int points;
};