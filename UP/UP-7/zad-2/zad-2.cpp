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
int minNum(int arr[100][100], int N, int M)
{
	int minNum = arr[0][0];
	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j < M; j++)
		{
			if (minNum > arr[i][j])
				minNum = arr[i][j];
		}
	}
	return minNum;
}

int main()
{
	int N, M;
	std::cin >> N >> M;
	int arr[100][100];

	readArr(arr, N, M);
	std::cout << minNum(arr, N, M);
}