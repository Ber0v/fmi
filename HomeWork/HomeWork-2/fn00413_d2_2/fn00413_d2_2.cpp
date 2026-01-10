/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2025/2026
*
* @author Александър Беров
* @idnumber 4MI0700413
* @task 2
* @compiler VC
*
*/

#include <iostream>

long long waysCounter(const char* string)
{
	long long ways[101];
	int last[128]{ 0 };

	ways[0] = 1;

	int i = 1;
	while (string[i - 1] != '\0')
	{
		ways[i] = 2 * ways[i - 1];

		unsigned char index = string[i - 1];

		if (last[index] != 0)
		{
			ways[i] -= ways[last[index] - 1];
		}

		last[index] = i;
		i++;
	}

	return ways[i - 1] - 1;
}

int main()
{
	char string[101];
	std::cin >> string;

	std::cout << waysCounter(string);
}