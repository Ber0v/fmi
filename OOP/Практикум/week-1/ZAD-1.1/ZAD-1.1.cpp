#include <iostream>

bool isEven(int num)
{
	return num % 2 == 0;
}

int countOfElement(int* arr, int size, bool (*pred)(int))
{
	if (!arr)return 0;
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (pred(arr[i])) count++;
	}
	return count;
}

int main()
{
	int arr[] = { 1, 2, 3, 4,5,6 };

	std::cout << countOfElement(arr, 6, isEven);
}