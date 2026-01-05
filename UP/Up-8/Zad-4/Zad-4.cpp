#include <iostream>
int getLength(char* str)
{
	char* currPtr = str;

	while ((currPtr + 1) != '\0')
	{
		currPtr++;
	}

	return currPtr - str;
}

int main()
{
	char str[100];
	std::cin >> str;

	std::cout << getLength(str);
}