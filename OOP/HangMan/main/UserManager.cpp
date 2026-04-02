#include "UserManager.h"
#include <fstream>
#include <cstdio>

void UserManager::addUser(const User& user)
{
	if (userExists(user.getName()))
	{
		std::cout << "User already exists\n";
		return;
	}

	std::ofstream file(fileName, std::ios::binary | std::ios::app);

	if (!file.is_open())
	{
		std::cout << "File open error\n";
		return;
	}

	if (!writeUser(file, user))
	{
		std::cout << "Write error\n";
	}
}

void UserManager::printAllUsers() const
{
	std::ifstream file(fileName, std::ios::binary);

	if (!file.is_open())
	{
		std::cout << "File open error\n";
		return;
	}

	User temp;
	while (readUser(file, temp))
	{
		temp.printUser();
	}
}

bool UserManager::userExists(const string& name) const
{
	std::ifstream file(fileName, std::ios::binary);

	if (!file.is_open())
	{
		std::cout << "File open error\n";
		return false;
	}

	User temp;
	while (readUser(file, temp))
	{
		if (temp.getName() == name)
			return true;
	}

	return false;
}

bool UserManager::loadUser(const string& name, User& result) const
{
	std::ifstream file(fileName, std::ios::binary);

	if (!file.is_open())
	{
		std::cout << "File open error\n";
		return false;
	}

	User temp;
	while (readUser(file, temp))
	{
		if (temp.getName() == name)
		{
			result = temp;
			return true;
		}
	}

	return false;
}

void UserManager::updateUser(const User& user)
{
	std::ifstream in(fileName, std::ios::binary);
	std::ofstream out("temp.dat", std::ios::binary);

	if (!in.is_open() || !out.is_open())
	{
		std::cout << "File open error\n";
		return;
	}

	User current;
	while (readUser(in, current))
	{
		if (current.getName() == user.getName())
		{
			if (!writeUser(out, user))
			{
				std::cout << "Write error\n";
				in.close();
				out.close();
				return;
			}
		}
		else
		{
			if (!writeUser(out, current))
			{
				std::cout << "Write error\n";
				in.close();
				out.close();
				return;
			}
		}
	}

	in.close();
	out.close();

	std::remove(fileName);
	std::rename("temp.dat", fileName);
}

bool UserManager::readUser(std::ifstream& file, User& user) const
{
	int nameLen;
	file.read((char*)&nameLen, sizeof(nameLen));

	if (file.eof())
		return false;

	if (!file || nameLen <= 0 || nameLen > 1000)
		return false;

	char* buffer = new char[nameLen + 1];
	if (!buffer)
		return false;

	file.read(buffer, nameLen);
	if (!file)
	{
		delete[] buffer;
		return false;
	}

	buffer[nameLen] = '\0';

	int points;
	file.read((char*)&points, sizeof(points));
	if (!file)
	{
		delete[] buffer;
		return false;
	}

	user = User(buffer, points);
	delete[] buffer;
	return true;
}

bool UserManager::writeUser(std::ofstream& file, const User& user) const
{
	int nameLen = user.getName().len();
	int points = user.getPoints();

	file.write((const char*)&nameLen, sizeof(nameLen));
	file.write(user.getName().c_str(), nameLen);
	file.write((const char*)&points, sizeof(points));

	return (bool)file;
}