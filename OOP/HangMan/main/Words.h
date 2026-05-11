#pragma once
#include "string.h"

class Words
{
public:
	const string getRandomWord() const;

	void addWord(const string& other);

private:
	bool readWords(std::ifstream& file, Words& user) const;
	bool writeWords(std::ofstream& file, const Words& user) const;

private:
	const char* fileName = "words.txt";
	string data;
	int lenght;
};