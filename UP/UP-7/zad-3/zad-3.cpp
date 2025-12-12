#include <iostream>

void readArr(int arr[100][100], int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			std::cin >> arr[i][j];
		}
	}
}
void writeArr(int arr1[100][100], int arr2[100][100], int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			std::cout << arr1[i][j] + arr2[i][j];
			std::cout << ' ';
		}
		std::cout << '\n';
	}
}

int main()
{
	int N, M;
	std::cin >> N >> M;
	int arr1[100][100];
	int arr2[100][100];


	readArr(arr1, N, M);
	readArr(arr2, N, M);
	writeArr(arr1, arr2, N, M);
}