#include "user.h"
#include <iostream>

using namespace std;

void copyString(char* dest, const char* src)
{
	int i = 0;

	while (src[i] != '\0' && i < 127)
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';
}

void setUser(User& user, const char* name, const char* email, const char* password)
{
	copyString(user.name, name);
	copyString(user.email, email);
	copyString(user.password, password);
}

void printUser(const User& user)
{
	cout << "Name: " << user.name << '\n';
	cout << "Email: " << user.email << '\n';
	cout << "Password: " << user.password << '\n';
}

bool writeUser(ofstream& file, const User& user)
{
	if (!file.is_open())
	{
		return false;
	}

	file.write((const char*)&user, sizeof(User));

	if (!file.good())
	{
		return false;
	}

	return true;
}

bool readUser(ifstream& file, User& user)
{
	if (!file.is_open())
	{
		return false;
	}

	file.read((char*)&user, sizeof(User));

	if (!file.good())
	{
		return false;
	}

	return true;
}