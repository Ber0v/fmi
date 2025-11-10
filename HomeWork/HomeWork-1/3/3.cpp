#include <iostream>

unsigned long long pow10(unsigned int k)
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
	return a * pow10(digits(b)) + b;
}

unsigned long long sortDigitsDesc(unsigned long long x)
{
	int c0 = 0, c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0, c7 = 0, c8 = 0, c9 = 0;
	if (x == 0)
	{
		c0 = 1;
	}
	while (x > 0)
	{
		int d = x % 10;
		switch (d)
		{
		case 0: c0++; break;
		case 1: c1++; break;
		case 2: c2++; break;
		case 3: c3++; break;
		case 4: c4++; break;
		case 5: c5++; break;
		case 6: c6++; break;
		case 7: c7++; break;
		case 8: c8++; break;
		case 9: c9++; break;
		}
		x /= 10;
	}

	unsigned long long r = 0;
	while (c9-- > 0) r = r * 10 + 9;
	while (c8-- > 0) r = r * 10 + 8;
	while (c7-- > 0) r = r * 10 + 7;
	while (c6-- > 0) r = r * 10 + 6;
	while (c5-- > 0) r = r * 10 + 5;
	while (c4-- > 0) r = r * 10 + 4;
	while (c3-- > 0) r = r * 10 + 3;
	while (c2-- > 0) r = r * 10 + 2;
	while (c1-- > 0) r = r * 10 + 1;
	while (c0-- > 0) r = r * 10;

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