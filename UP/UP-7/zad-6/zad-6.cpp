#include <iostream>
const int rows = 10;

void readArr(int arr[rows][rows], int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			std::cin >> arr[i][j];
		}
	}
}

void writeArr(int arr[rows][rows], int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			std::cout << arr[i][j] << ' ';
		}
		std::cout << '\n';
	}
}

int main()
{
	int N1, M1;
	std::cin >> N1 >> M1;
	int arr1[rows][rows];
	readArr(arr1, N1, M1);

	int N2, M2;
	std::cin >> N2 >> M2;
	int arr2[rows][rows];
	readArr(arr2, N2, M2);

	if (M1 != N2)
	{
		std::cout << "Invalid input!";
		return 0;
	}

	int result[rows][rows];

	for (int i = 0; i < N1; i++)
	{
		for (int j = 0; j < M2; j++)
		{
			int sum = 0;
			for (int k = 0; k < M1; k++)
			{
				sum += arr1[i][k] * arr2[k][j];
			}
			result[i][j] = sum;
		}
	}

	writeArr(result, N1, M2);
}
