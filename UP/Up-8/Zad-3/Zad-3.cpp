#include <iostream>

void operatorPlusEquals(int& a, int& b)
{
	a += b;
}

int main()
{
	int a = 5;
	int b = 3;

	operatorPlusEquals(a, b);

	std::cout << a;
}