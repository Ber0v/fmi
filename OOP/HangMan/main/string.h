#pragma once
#include <iostream>

class string
{
public:
	string();
	string(const char* str);
	string(const string& str);
	string& operator=(const string& str);
	bool operator==(const string& other) const;
	char& operator[](int index);
	const char& operator[](int index) const;
	friend std::ostream& operator<<(std::ostream& os, const string& str);
	~string();

	//methods
	int len() const;
	bool isexist(char simbol) const;
	const char* c_str() const;

private:
	void copy(const char* str);
	void clear();

private:
	char* data;
	int count;
};