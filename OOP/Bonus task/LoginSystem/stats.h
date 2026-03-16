#pragma once

struct Stats
{
	int registrations;
	int successfulLogins;
	int failedLogins;
};

void initStats(Stats& stats);
void printStats(const Stats& stats);

bool saveStats(const Stats& stats, const char* fileName);
bool loadStats(Stats& stats, const char* fileName);

bool saveLastSession(const char* fileName, const char* email);
bool loadLastSession(const char* fileName, char email[128]);