#include <iostream>

bool valid(const char s[], int n)
{
	int bal = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(')
		{
			bal++;
		}
		else if (s[i] == ')')
		{
			bal--;
		}
		if (bal < 0)
		{
			return false;
		}
	}
	return bal == 0;
}

int main()
{
	char s[11];
	std::cin >> s;

	int len = 0;
	while (s[len])
	{
		len++;
	}

	std::cout << std::boolalpha << valid(s, len);
}
