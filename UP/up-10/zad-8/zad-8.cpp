#include <iostream>

bool isExist(const char* text, const char pat)
{
	if (*text == pat)
	{
		return true;
	}
	if (*text == '\0')
	{
		return false;
	}

	return isExist(text + 1, pat);
}

int main()
{
	char text[] = "mazna";
	char pattern = 'z';

	std::cout << std::boolalpha << isExist(text, pattern);
}