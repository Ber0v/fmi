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
	clear();

	if (!str)
	{
		count = 0;
		data = new char[1];
		data[0] = '\0';
		return;
	}

	count = strlen(str);
	data = new char[count + 1];
	strcpy(data, str);
}

void string::clear()
{
	delete[] data;
	data = nullptr;
	count = 0;
}