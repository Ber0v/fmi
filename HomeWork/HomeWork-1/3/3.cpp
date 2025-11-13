#include <iostream>

unsigned long long pow(unsigned int k)
{
	unsigned long long p = 1;
	for (unsigned int i = 0; i < k; i++)
	{
		p *= 10;
	}
	return p;
}

unsigned int digits(unsigned long long x)
{
	if (x == 0)
	{
		return 1;
	}
	unsigned int c = 0;
	while (x > 0)
	{
		c++;
		x /= 10;
	}
	return c;
}

unsigned long long concat(unsigned long long a, unsigned long long b)
{
	return a * pow(digits(b)) + b;
}

unsigned long long countDigit(unsigned long long x, int d)
{
	unsigned long long c = 0;
	while (x > 0)
	{
		if (x % 10 == d) c++;
		x /= 10;
	}
	return c;
}

unsigned long long sortDigitsDesc(unsigned long long x)
{
	unsigned long long r = 0;
	for (int d = 9; d >= 0; d--)
	{
		unsigned long long cnt = countDigit(x, d);
		while (cnt-- > 0)
		{
			r = r * 10 + d;
		}
	}
	return r;
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

		unsigned long long c = concat(A, B);
		unsigned long long s = sortDigitsDesc(c);

		if (s > best)
		{
			if (best != s)
			{
				second = best;
			}
			best = s;
		}
		else if (s < best && s > second)
		{
			second = s;
		}
	}

	std::cout << best << '\n' << second << '\n';
}