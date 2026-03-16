#include <iostream>
#include <cstring>
#include "system.h"
#include "stats.h"

using namespace std;

int main()
{
	System system;
	Stats stats;

	initSystem(system);
	initStats(stats);

	if (!loadSystem(system, "users.dat"))
	{
		cout << "Could not load users.dat\n";
	}

	if (!loadStats(stats, "stats.txt"))
	{
		cout << "Could not load stats.txt\n";
	}

	char lastLoggedUser[128];

	if (loadLastSession("last_session.txt", lastLoggedUser))
	{
		cout << "Last logged user: " << lastLoggedUser << '\n';
	}

	char command[128];

	while (true)
	{
		cout << "Enter command:\n> ";
		cin.getline(command, 128);

		if (strcmp(command, "register") == 0)
		{
			char name[128];
			char email[128];
			char password[128];

			cout << "Enter name:\n> ";
			cin.getline(name, 128);

			cout << "Enter email:\n> ";
			cin.getline(email, 128);

			cout << "Enter password:\n> ";
			cin.getline(password, 128);

			if (registerUser(system, name, email, password))
			{
				cout << "Registration successful\n";
				stats.registrations++;

				if (!saveSystem(system, "users.dat"))
				{
					cout << "Error while saving users.dat\n";
				}
			}
			else
			{
				cout << "Registration failed\n";
			}

			if (!saveStats(stats, "stats.txt"))
			{
				cout << "Error while saving stats.txt\n";
			}
		}
		else if (strcmp(command, "login") == 0)
		{
			char email[128];
			char password[128];

			cout << "Enter email:\n> ";
			cin.getline(email, 128);

			cout << "Enter password:\n> ";
			cin.getline(password, 128);

			if (loginUser(system, email, password))
			{
				cout << "Login successful\n";
				stats.successfulLogins++;

				if (!saveLastSession("last_session.txt", email))
				{
					cout << "Error while saving last_session.txt\n";
				}
			}
			else
			{
				cout << "Login failed\n";
				stats.failedLogins++;
			}

			if (!saveStats(stats, "stats.txt"))
			{
				cout << "Error while saving stats.txt\n";
			}
		}
		else if (strcmp(command, "stats") == 0)
		{
			printStats(stats);
		}
		else if (strcmp(command, "exit") == 0)
		{
			if (!saveSystem(system, "users.dat"))
			{
				cout << "Error while saving users.dat\n";
			}

			if (!saveStats(stats, "stats.txt"))
			{
				cout << "Error while saving stats.txt\n";
			}

			break;
		}
		else if (strlen(command) == 0)
		{
			continue;
		}
		else
		{
			cout << "Invalid command\n";
		}
	}

	return 0;
}