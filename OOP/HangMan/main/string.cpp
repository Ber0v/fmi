#pragma warning(disable:4996)
#include "string.h"
#include <cstring>

string::string()
{
	copy(nullptr);
}

string::string(const char* str)
{
	copy(str);
}

string::string(const string& str)
{
	copy(str.data);
}

string& string::operator=(const string& str)
{
	if (this != &str)
	{
		clear();
		copy(str.data);
	}

	return *this;
}

char& string::operator[](int index)
{
	if (index < 0 || index >= count)
	{
		throw "Index out of range";
	}
	return data[index];
}

const char& string::operator[](int index) const
{
	if (index < 0 || index >= count)
	{
		throw "Index out of range";
	}
	return data[index];
}

std::ostream& operator<<(std::ostream& os, const string& str)
{
	return os << str.data;
}

string::~string()
{
	clear();
}

int string::len() const
{
	return count;
}

bool string::isexist(char simbol) const
{
	for (int i = 0; i < count; i++)
	{
		if (data[i] == simbol) return true;
	}
	return false;
}

void string::copy(const char* str)
{
	if (!str)
		throw std::exception("Invalid string\n");

	count = strlen(str);
	char* copy = new char[count + 1];
	strcpy(copy, str);
	delete[] this->data;
	this->data = copy;
}

void string::clear()
{
	delete[] data;
	data = nullptr;
	count = 0;
}