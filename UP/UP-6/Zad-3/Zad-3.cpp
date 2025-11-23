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

void writeArray(int arr1[], int arr2[], int arr3[], int count)
{
	for (int i = 0; i < count; i++)
	{
		if (arr1[i] >= 0)
			std::cout << arr1[i] << ' ';
		if (arr2[i] >= 0)
			std::cout << arr2[i] << ' ';
		if (arr3[i] >= 0)
			std::cout << arr3[i] << ' ';
	}
}

int main()
{
	int n1, n2, n3;
	int arr1[10];
	std::cin >> n1;
	readArray(arr1, n1);
	int arr2[10];
	std::cin >> n2;
	readArray(arr2, n2);
	int arr3[10];
	std::cin >> n3;
	readArray(arr3, n3);

	int count = 0;
	if (n1 > n2 && n1 > n3)
	{
		count = n1;
	}
	else if (n2 > n1 && n2 > n3)
	{
		count = n2;
	}
	else
	{
		count = n3;
	}
	writeArray(arr1, arr2, arr3, count);
}