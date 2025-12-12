#include <iostream>
const int rows = 10;
void readArr(int arr[rows][rows], int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cin >> arr[i][j];
		}
	}
}

void writeArr(int arr[rows][rows], int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cout << arr[i][j];
			std::cout << ' ';
		}
		std::cout << '\n';
	}
}

void tranponirane(int arr[rows][rows], int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N; j++)

		{
			int num = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = num;
		}
	}
}

int main()
{
	int N;
	std::cin >> N;
	int arr[rows][rows];

	readArr(arr, N);
	tranponirane(arr, N);
	writeArr(arr, N);
}