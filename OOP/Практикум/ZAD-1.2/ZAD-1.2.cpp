#include <iostream>

bool isPrime(int num)
{
	if (num <= 1)return false;
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)return false;
	}

	return true;
}

int* Filter(int* arr, int size, int& resSize, bool (*pred)(int))
{
	if (!arr) return 0;
	int newSize = 0;
	for (int i = 0; i < size; i++)
	{
		if (pred(arr[i])) newSize++;
	}
	int* newArr = new (std::nothrow) int[newSize];
	if (!newArr) return nullptr;

	for (int i = 0; i < size; i++)
	{
		if (pred(arr[i])) newArr[resSize++] = arr[i];
	}
	return newArr;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int resSize = 0;
	int* filter = Filter(arr, 8, resSize, isPrime);

	for (int i = 0; i < resSize; i++)
	{
		std::cout << filter[i] << ' ';
	}
	delete[] filter;
}