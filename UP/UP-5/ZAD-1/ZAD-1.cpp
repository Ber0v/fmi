#include <iostream>

long long Result(int a, int b)
{
	long long res = 1;

	for (int i = 0; i < b; i++)
	{
		res *= a;
	}

	return res;
}

int main()
{
	int a, b;
	std::cin >> a >> b;

	std::cout << Result(a, b);
}