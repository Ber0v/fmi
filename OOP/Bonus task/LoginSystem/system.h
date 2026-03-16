#pragma once
#include "user.h"

struct System
{
	User users[100];
	int count;
};

void initSystem(System& system);

bool saveSystem(const System& system, const char* fileName);
bool loadSystem(System& system, const char* fileName);

bool registerUser(System& system, const char* name, const char* email, const char* password);
bool loginUser(const System& system, const char* email, const char* password);

int findUserByName(const System& system, const char* name);
int findUserByEmail(const System& system, const char* email);
bool areEqualStrings(const char* first, const char* second);