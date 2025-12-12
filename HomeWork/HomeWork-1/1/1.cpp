#include <iostream>

void line(int size, int level, bool mid)
{
	for (int i = 1;i <= level;i++)
	{
		std::cout << i;
	}
	for (int i = 0;i < size + 2 * (size - level);i++)
	{
		std::cout << (mid ? '-' : ' ');
	}
	for (int i = level;i >= 1;i--)
	{
		std::cout << i;
	}
	std::cout << '\n';
}

void emptyLines(int line)
{
	for (int i = 0;i < line;i++)
	{
		std::cout << '\n';
	}
}

int main()
{
	int N;
	std::cin >> N;

	int h = 2 * N - 1;
	int top = (25 - h) / 2;
	int left = (80 - 3 * N) / 2;
	int below = 25 - top - h;

	emptyLines(top);
	for (int i = 1;i <= N;i++) {
		for (int s = 0;s < left;s++)
		{
			std::cout << ' ';
		}
		line(N, i, i == N);
	}
	for (int i = N - 1;i >= 1;i--) {
		for (int s = 0;s < left;s++)
		{
			std::cout << ' ';
		}
		line(N, i, false);
	}
	emptyLines(below);
}
