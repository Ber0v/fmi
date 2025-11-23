#include <iostream>

void Division(int a, int b)
{
	std::cout << a / b << ' ' << a % b << '/' << b;
}

int main()
{
	int a, b;
	std::cin >> a, b;

	Division(a, b);
}