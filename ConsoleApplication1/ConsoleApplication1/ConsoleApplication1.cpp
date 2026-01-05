#include <iostream>

int myAtoi(const char* str)
{
	int i = 0;
	int result = 0;
	int sign = 1;

	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}

	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}

	return result * sign;
}

int main()
{
	char text[100];
	std::cin.getline(text, 100);

	std::cout << myAtoi(text);
	return 0;
}
