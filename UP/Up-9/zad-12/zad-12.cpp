#include <iostream>

int** allocMatrix(int n)
{
	int** m = new int* [n];
	for (int i = 0; i < n; i++)
		m[i] = new int[n];
	return m;
}

void freeMatrix(int** m, int n)
{
	for (int i = 0; i < n; i++)
		delete[] m[i];
	delete[] m;
}

void readMatrix(int** m, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			std::cin >> m[i][j];
}

void printSubMatrix(int** m, int rowStart, int rowEnd, int colStart, int colEnd)
{
	for (int i = rowStart; i < rowEnd; i++)
	{
		for (int j = colStart; j < colEnd; j++)
		{
			std::cout << m[i][j];
			if (j != colEnd - 1) std::cout << ' ';
		}
		std::cout << '\n';
	}
}

void printAllQuads(int** m, int n)
{
	int half = n / 2;

	// 1) горе-ляво
	printSubMatrix(m, 0, half, 0, half);
	std::cout << '\n';

	// 2) горе-дясно
	printSubMatrix(m, 0, half, half, n);
	std::cout << '\n';

	// 3) долу-ляво
	printSubMatrix(m, half, n, 0, half);
	std::cout << '\n';

	// 4) долу-дясно
	printSubMatrix(m, half, n, half, n);
}

int main()
{
	int n;
	std::cin >> n;

	int** matrix = allocMatrix(n);
	readMatrix(matrix, n);

	printAllQuads(matrix, n);

	freeMatrix(matrix, n);
	return 0;
}