#include <iostream>

int stepen(int n, int k)
{
	if (k == 1)
	{
		return n;
	}
	return n * stepen(n, k - 1);
}

int main()
{
	int n, k;
	std::cin >> n >> k;

	std::cout << stepen(n, k);
}