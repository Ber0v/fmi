#include <iostream>

bool isSame(const char* text, const char* secondText)
{
	if (*text != *secondText)
	{
		return false;
	}
	if (*text == '\0')
	{
		return true;
	}

	return isSame(text + 1, secondText + 1);
}

int main()
{
	char text[] = "Hello";
	char secondText[] = "Hello";

	std::cout << std::boolalpha << isSame(text, secondText);
}