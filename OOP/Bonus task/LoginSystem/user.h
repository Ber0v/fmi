#pragma once
#include <fstream>

struct User
{
	char name[128];
	char email[128];
	char password[128];
};

void copyString(char* dest, const char* src);
void setUser(User& user, const char* name, const char* email, const char* password);
void printUser(const User& user);

bool writeUser(std::ofstream& file, const User& user);
bool readUser(std::ifstream& file, User& user);