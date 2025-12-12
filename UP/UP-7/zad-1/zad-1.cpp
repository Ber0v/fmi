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
void writeArr(int arr[100][100], int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			std::cout << arr[i][j];
			std::cout << ' ';
		}
		std::cout << '\n';
	}
}

int main()
{
	int N, M;
	std::cin >> N >> M;
	int arr[100][100];

	readArr(arr, N, M);
	writeArr(arr, N, M);

}