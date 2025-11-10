#include <iostream>

bool isPrime(long long x)
{
	if (x < 2)
	{
		return false;
	}
	if (x % 2 == 0)
	{
		return x == 2;
	}
	for (long long i = 3; i <= x / i; i += 2)
	{
		if (x % i == 0)
		{
			return false;
		}
	}
	return true;
}

bool uniqueDigits(long long x)
{
	long long seen = 0;
	while (x > 0)
	{
		int d = x % 10;
		long long check = 1;
		for (int i = 0; i < d; i++)
		{
			check *= 10;
		}
		if (seen / check % 10 == 1)
		{
			return false;
		}
		seen += check;
		x /= 10;
	}
	return true;
}

int main()
{
	long long N;
	std::cin >> N;

	for (long long d = 0;; ++d)
	{
		long long a = (N >= d ? N - d : -1);
		if (a >= 2 && uniqueDigits(a) && isPrime(a))
		{
			std::cout << a;
			break;
		}

		long long b = N + d;
		if (d > 0 && uniqueDigits(b) && isPrime(b))
		{
			std::cout << b;
			break;
		}
	}
}
