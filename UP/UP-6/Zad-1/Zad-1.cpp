#include <iostream>

void readArray(int arr[], int count)
{
	int num;
	for (int i = 0; i < count; i++)
	{
		std::cin >> num;
		arr[i] = num;
	}
}

void secondDegree(int arr[], int count)
{
	for (int i = 0; i < count; i++)
	{
		arr[i] *= arr[i];
	}
}

void writeArray(int arr[], int count)
{
	for (int i = 0; i < count; i++)
	{
		std::cout << arr[i] << ' ';
	}
}

int main()
{
	int n;
	std::cin >> n;
	int arr[32];
	readArray(arr, n);

	secondDegree(arr, n);

	writeArray(arr, n);
}