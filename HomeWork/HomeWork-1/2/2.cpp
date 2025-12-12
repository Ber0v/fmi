#include <iostream>

bool isPrime(long long num)
{
	if (num < 2)
	{
		return false;
	}
	if (num % 2 == 0)
	{
		return num == 2;
	}
	for (long long i = 3; i <= num / i; i += 2)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}

bool uniqueDigits(long long num)
{
	long long seen = 0;
	while (num > 0)
	{
		int digit = num % 10;
		long long check = 1;
		for (int i = 0; i < digit; i++)
		{
			check *= 10;
		}
		if (seen / check % 10 == 1)
		{
			return false;
		}
		seen += check;
		num /= 10;
	}
	return true;
}

int main()
{
	long long N;
	std::cin >> N;

	for (long long i = 0;; ++i)
	{
		long long leftNum = (N >= i ? N - i : -1);
		if (leftNum >= 2 && uniqueDigits(leftNum) && isPrime(leftNum))
		{
			std::cout << leftNum;
			break;
		}

		long long rightNum = N + i;
		if (i > 0 && uniqueDigits(rightNum) && isPrime(rightNum))
		{
			std::cout << rightNum;
			break;
		}
	}
}
