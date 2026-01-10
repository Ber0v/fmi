#include <iostream>
//Извикайте горната функция в main и освободете заделената памет правилно.

void readMatrix(int** matrix, int x, int y)
{
	for (int i = 0; i < y; i++)
	{
		for (int p = 0;p < x; p++)
		{

			std::cin >> matrix[i][p];
		}
	}
}
void writeMatrix(int** matrix, int x, int y)
{
	for (int i = 0; i < y; i++)
	{
		for (int p = 0;p < x; p++)
		{
			std::cout << matrix[i][p] << ' ';
		}
		std::cout << '\n';
	}
}

int main()
{
	int x = 5;
	int y = 3;

	int** matrix = new int* [y];
	for (int i = 0; i < y; i++)
	{
		matrix[i] = new int[x];
	}

	readMatrix(matrix, x, y);
	writeMatrix(matrix, x, y);

	for (int i = 0; i < y; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}