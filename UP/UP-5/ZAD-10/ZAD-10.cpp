#include <iostream>

bool isClosedInterval(int num, int a, int b)
{
	return num >= a && num <= b;
}

bool isIntervalValid(int a, int b)
{
	return a < b;
}

int main()
{
	int x, a, b, c, d, e, f;
	std::cin >> x >> a >> b >> c >> d >> e >> f;

	if (!isIntervalValid(a, b) || !isIntervalValid(c, d) || !isIntervalValid(e, f))
	{
		std::cout << "Invalid intervals!";
		return -1;
	}
	std::cout << std::boolalpha << ((isClosedInterval(x, a, b) || isClosedInterval(x, c, d)) && !isClosedInterval(x, e, f));
}