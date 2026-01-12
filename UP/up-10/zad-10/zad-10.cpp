#include <iostream>

int strlenRec(const char* str)
{
	if (*str == '\0')
	{
		return 0;
	}

	return 1 + strlenRec(str + 1);
}

bool isPalindromeRec(const char* str, int left, int right)
{
	if (left >= right)
	{
		return true;
	}

	if (str[left] != str[right])
	{
		return false;
	}

	return isPalindromeRec(str, left + 1, right - 1);
}

int main()
{
	char text[] = "madam";

	int len = strlenRec(text);
	std::cout << std::boolalpha << isPalindromeRec(text, 0, len - 1);
}