#include <iostream>
const int rows = 8;
void readArr(char arr[rows][rows], int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i % 2 != 0 && j % 2 == 0 ||
				i % 2 == 0 && j % 2 != 0)
				arr[i][j] = ' ';
			else
				arr[i][j] = '#';
		}
	}
}

void writeArr(char arr[rows][rows], int N)
{
	for (int i = N; i > 0; i--)
	{
		std::cout << i;
		for (int j = 0; j < N; j++)
		{
			std::cout << arr[i - 1][j];
		}
		std::cout << '\n';
	}
	std::cout << ' ';
	for (int i = 0; i < N; i++)
	{
		char sim = 'A' + i;
		std::cout << sim;
	}
}

void coordinateSystem(char arr[rows][rows], int N)
{
	char coordinat[3];
	std::cin >> coordinat;

	while (coordinat[0] != 'Q')
	{
		int x = coordinat[0] - 'A';
		int y = coordinat[1] - '1';
		arr[y][x] = '0';
		writeArr(arr, N);
		std::cin >> coordinat;
	}
}

int main()
{
	int N = 8;
	char arr[rows][rows];

	readArr(arr, N);
	writeArr(arr, N);
	coordinateSystem(arr, N);
}