#pragma once
#include "User.h"

class UserManager
{
public:
	void addUser(const User& user);

	void printAllUsers() const;
	bool userExists(const string& name) const;
	bool loadUser(const string& name, User& result) const;
	void updateUser(const User& user);

private:
	bool readUser(std::ifstream& file, User& user) const;
	bool writeUser(std::ofstream& file, const User& user) const;

private:
	const char* fileName = "users.dat";
};