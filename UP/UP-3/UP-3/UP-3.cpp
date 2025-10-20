#include <iostream>

int main()
{
    int n, k;
	int s;
    std::cin >> n >> k;
	s = n;

	for (int i = 1; i < k; i++)
	{
		n *= s;
	}
	std::cout << n;
}