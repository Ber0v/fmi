#include "stats.h"
#include <iostream>
#include <fstream>

using namespace std;

void initStats(Stats& stats)
{
	stats.registrations = 0;
	stats.successfulLogins = 0;
	stats.failedLogins = 0;
}

void printStats(const Stats& stats)
{
	cout << "Registrations: " << stats.registrations << '\n';
	cout << "Successful logins: " << stats.successfulLogins << '\n';
	cout << "Failed logins: " << stats.failedLogins << '\n';
}

bool saveStats(const Stats& stats, const char* fileName)
{
	ofstream file(fileName);

	if (!file.is_open())
	{
		return false;
	}

	file << stats.registrations << '\n';
	file << stats.successfulLogins << '\n';
	file << stats.failedLogins << '\n';

	if (!file.good())
	{
		file.close();
		return false;
	}

	file.close();

	if (!file)
	{
		return false;
	}

	return true;
}

bool loadStats(Stats& stats, const char* fileName)
{
	ifstream file(fileName);

	if (!file.is_open())
	{
		return false;
	}

	file >> stats.registrations >> stats.successfulLogins >> stats.failedLogins;

	if (!file.good())
	{
		file.close();
		initStats(stats);
		return false;
	}

	file.close();
	return true;
}

bool saveLastSession(const char* fileName, const char* email)
{
	ofstream file(fileName);

	if (!file.is_open())
	{
		return false;
	}

	file << email;

	if (!file.good())
	{
		file.close();
		return false;
	}

	file.close();

	if (!file)
	{
		return false;
	}

	return true;
}

bool loadLastSession(const char* fileName, char email[128])
{
	ifstream file(fileName);

	if (!file.is_open())
	{
		return false;
	}

	file.getline(email, 128);

	if (!file.good() && !file.eof())
	{
		file.close();
		return false;
	}

	if (email[0] == '\0')
	{
		file.close();
		return false;
	}

	file.close();
	return true;
}