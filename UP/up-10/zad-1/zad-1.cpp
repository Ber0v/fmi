#include <iostream>

long long factoriel(int n)
{
	if (n <= 1)
	{
		return 1;
	}
	return n * factoriel(n - 1);
}

int main()
{
	int n;
	std::cin >> n;

	std::cout << factoriel(n);
}