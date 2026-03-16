#include <iostream>
#include "system.h"
#include <fstream>

using namespace std;

void initSystem(System& system)
{
	system.count = 0;
}

bool areEqualStrings(const char* first, const char* second)
{
	int i = 0;

	while (first[i] != '\0' || second[i] != '\0')
	{
		if (first[i] != second[i])
		{
			return false;
		}

		i++;
	}

	return true;
}

int findUserByName(const System& system, const char* name)
{
	for (int i = 0; i < system.count; i++)
	{
		if (areEqualStrings(system.users[i].name, name))
		{
			return i;
		}
	}

	return -1;
}

int findUserByEmail(const System& system, const char* email)
{
	for (int i = 0; i < system.count; i++)
	{
		if (areEqualStrings(system.users[i].email, email))
		{
			return i;
		}
	}

	return -1;
}

bool saveSystem(const System& system, const char* fileName)
{
	ofstream file(fileName, ios::binary);

	if (!file.is_open())
	{
		return false;
	}

	file.write((const char*)&system.count, sizeof(system.count));

	if (!file.good())
	{
		file.close();
		return false;
	}

	for (int i = 0; i < system.count; i++)
	{
		if (!writeUser(file, system.users[i]))
		{
			file.close();
			return false;
		}
	}

	file.close();

	if (!file)
	{
		return false;
	}

	return true;
}

bool loadSystem(System& system, const char* fileName)
{
	ifstream file(fileName, ios::binary);

	if (!file.is_open())
	{
		return false;
	}

	int count = 0;
	file.read((char*)&count, sizeof(count));

	if (!file.good())
	{
		file.close();
		return false;
	}

	if (count < 0 || count > 100)
	{
		file.close();
		return false;
	}

	system.count = count;

	for (int i = 0; i < system.count; i++)
	{
		if (!readUser(file, system.users[i]))
		{
			system.count = 0;
			file.close();
			return false;
		}
	}

	file.close();
	return true;
}

bool registerUser(System& system, const char* name, const char* email, const char* password)
{
	if (system.count >= 100)
	{
		cout << "User limit reached\n";
		return false;
	}

	if (findUserByEmail(system, email) != -1)
	{
		cout << "Email already registered\n";
		return false;
	}

	if (findUserByName(system, name) != -1)
	{
		cout << "Username already taken\n";
		return false;
	}

	setUser(system.users[system.count], name, email, password);
	system.count++;

	return true;
}

bool loginUser(const System& system, const char* email, const char* password)
{
	int index = findUserByEmail(system, email);

	if (index == -1)
	{
		return false;
	}

	if (!areEqualStrings(system.users[index].password, password))
	{
		return false;
	}

	return true;
}