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

void foo(int*& arrNums, int& size, int& capacity, int a)
{
	if (capacity > size)
	{
		arrNums[size++] = a;
		return;
	}

	capacity *= 2;
	int* coppy = coppyarr(arrNums, capacity, size);
	size++;

	delete[] arrNums;
	arrNums = coppy;

	arrNums[size - 1] = a;
}

int main()
{
	int size = 5;
	int capacity = 20;
	int* arrNums = new int[capacity] { 1, 20, 3, 4, 8 };

	foo(arrNums, size, capacity, 20);
	printArr(arrNums, size);

	delete[] arrNums;
}