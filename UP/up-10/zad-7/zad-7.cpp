#include <iostream>

int reverseNum(int n, int res = 0)
{
	if (n == 0)
	{
		return res;
	}

	return reverseNum(n / 10, (res * 10) + (n % 10));
}

int main()
{
	int n;
	std::cin >> n;

	std::cout << reverseNum(n);
}