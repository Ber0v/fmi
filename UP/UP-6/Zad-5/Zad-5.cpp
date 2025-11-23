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

int inversion(int arr[], int count)
{
	int countInv = 0;
	for (int i = 0; i < count; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			if (arr[i] > arr[j])
				countInv++;
		}
	}
	return countInv;
}

int main()
{
	int n;
	std::cin >> n;
	int arr[32];
	readArray(arr, n);
	std::cout << inversion(arr, n);
}