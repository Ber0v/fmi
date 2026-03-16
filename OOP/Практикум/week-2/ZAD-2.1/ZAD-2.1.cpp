#include <iostream>

bool isEven(int n)
{
	return !(n & 1);
}

int main()
{
	int n;
	std::cin >> n;
	std::cout << std::boolalpha << isEven(n);
}