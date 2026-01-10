#include <iostream>
int* coppyarr(const int* arrNums, int capacity, int size)
{
	int* str = new int[capacity] {0};
	for (int i = 0; i < size; i++)
	{
		str[i] = arrNums[i];
	}

	return str;
}

void printArr(const int* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << arr[i] << ' ';
	}
}

void foo(int*& arrNums, int& size, int& capacity)
{
	arrNums[--size] = 0;
	if (size <= capacity / 4)
	{
		capacity /= 2;
		int* coppy = coppyarr(arrNums, capacity, size);

		delete[] arrNums;
		arrNums = coppy;
	}
}

int main()
{
	int size = 5;
	int capacity = 20;
	int* arrNums = new int[capacity] { 1, 20, 3, 4, 8 };

	foo(arrNums, size, capacity);
	printArr(arrNums, size);

	delete[] arrNums;
}