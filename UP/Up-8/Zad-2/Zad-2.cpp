#include <iostream>
void replase(char* input, char* result)
{
	for (int i = 0; input[i]; i++)
	{
		if (input[i] >= '0' && input[i] <= '9')
		{
			result[i] = ' ';
		}
		else
		{
			result[i] = input[i];
		}

		if (input[i + 1] == '\0')
		{
			result[i + 1] = '\0';
		}
	}

}

void print(char* string)
{
	for (int i = 0; string[i]; i++)
	{
		std::cout << string[i];
	}
}

int main()
{
	char str[100];
	char res[100];
	std::cin >> str;

	replase(str, res);
	print(res);
}