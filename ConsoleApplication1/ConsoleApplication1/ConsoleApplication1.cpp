#include <iostream>

void line(int i, int N)
{
	for (int j = 0; j < N; j++)
	{
		if (j % 2 == 0) std::cout << '*';
		else std::cout << ' ';
	}
}

void mid(int i, int N)
{
	for (int j = 0; j < N; j++)
	{
		if (j == N / 2) std::cout << '0';
		else std::cout << ' ';
	}
}

void secondsLine(int i, int N)
{
	for (int j = 0; j < N; j++)
	{
		if (i % 2 == 0 && (j == 0 || j == N - 1)) std::cout << '*';
		else if (j == i) std::cout << '+';
		else if (j == N - i - 1) std::cout << '-';
		else std::cout << ' ';
	}
}

int main()
{
	int N;
	std::cin >> N;

	if (N > 25 || (N % 2 == 0)) {
		std::cout << "error";
		return 0;
	}

	for (int i = 0; i < N; i++)
	{
		if (i == 0 || i == N - 1) line(i, N);
		else if (i == N / 2) mid(i, N);
		else secondsLine(i, N);
		std::cout << '\n';
	}
}