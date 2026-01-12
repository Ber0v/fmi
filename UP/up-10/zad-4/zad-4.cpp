#include <iostream>

int sumArr(int n)
{
	if (n % 10 == 0)
	{
		return n;
	}
	return n % 10 + sumArr(n / 10);
}

int main()
{
	int n;
	std::cin >> n;

	std::cout << sumArr(n);
}