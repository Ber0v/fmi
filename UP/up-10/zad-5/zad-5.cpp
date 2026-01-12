#include <iostream>

void printLine(int n, int i = 1)
{
	if (i > n)
	{
		return;
	}

	std::cout << i << ' ';
	printLine(n, i + 1);
}

void printTriangle(int n)
{
	if (n == 0)
	{
		return;
	}

	printLine(n);
	std::cout << '\n';
	printTriangle(n - 1);
}

int main()
{
	int n;
	std::cin >> n;
	printTriangle(n);
}