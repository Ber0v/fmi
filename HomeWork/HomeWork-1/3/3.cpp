#include <iostream>

unsigned long long pow(unsigned int num)
{
	unsigned long long result = 1;
	for (unsigned int i = 0; i < num; i++)
	{
		result *= 10;
	}
	return result;
}

unsigned int digits(unsigned long long num)
{
	if (num == 0)
	{
		return 1;
	}
	unsigned int digitCount = 0;
	while (num > 0)
	{
		digitCount++;
		num /= 10;
	}
	return digitCount;
}

unsigned long long concat(unsigned long long a, unsigned long long b)
{
	return a * pow(digits(b)) + b;
}

unsigned long long countDigit(unsigned long long num, int digit)
{
	unsigned long long count = 0;
	while (num > 0)
	{
		if (num % 10 == digit) count++;
		num /= 10;
	}
	return count;
}

unsigned long long sortDigitsDesc(unsigned long long num)
{
	unsigned long long result = 0;
	for (int i = 9; i >= 0; i--)
	{
		unsigned long long countdigit = countDigit(num, i);
		while (countdigit-- > 0)
		{
			result = result * 10 + i;
		}
	}
	return result;
}

int main()
{
	int N;
	std::cin >> N;

	unsigned long long best = 0, second = 0;

	for (int i = 0; i < N; i++)
	{
		unsigned long long A, B;
		std::cin >> A >> B;

		unsigned long long concatNum = concat(A, B);
		unsigned long long sortedDigit = sortDigitsDesc(concatNum);

		if (sortedDigit > best)
		{
			if (best != sortedDigit)
			{
				second = best;
			}
			best = sortedDigit;
		}
		else if (sortedDigit < best && sortedDigit > second)
		{
			second = sortedDigit;
		}
	}

	std::cout << best << '\n' << second << '\n';
}