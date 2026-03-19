#include <iostream>

int timesTwo(int x)
{
	return x * 2;
}

bool isEven(int x)
{
	return x % 2 == 0;
}

int sum(int a, int b)
{
	return a + b;
}

template<typename T, typename U>
void map(const T* input, U* output, int size, U(*func)(T))
{
	for (int i = 0; i < size; i++)
	{
		output[i] = func(input[i]);
	}
}

template<typename T>
T* filter(const T* arr, int size, bool (*pred)(T), int& newSize)
{
	if (!arr || !pred) return nullptr;
	for (int i = 0; i < size; i++)
	{
		if (pred(arr[i]))
		{
			newSize++;
		}
	}
	T* newArr = new (std::nothrow) int[newSize];
	if (!newArr) return nullptr;
	for (int i = 0, j = 0; i < size; i++)
	{
		if (pred(arr[i]))
		{
			newArr[j++] = arr[i];
		}
	}
	return newArr;
}

template<typename T>
T fold(const T* arr, int size, T n, T(*f)(T, T))
{
	if (!arr || !f) return T();
	T sum = n;
	for (int i = 0; i < size; i++)
	{
		sum = f(sum, arr[i]);
	}
	return sum;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	int size = 5;

	int mapped[5];

	map(arr, mapped, size, timesTwo);

	std::cout << "map: ";
	for (int i = 0; i < size; i++)
	{
		std::cout << mapped[i] << ' ';
	}
	std::cout << '\n';

	int newSize = 0;
	int* filtered = filter(arr, size, isEven, newSize);

	std::cout << "filter: ";
	for (int i = 0; i < newSize; i++)
	{
		std::cout << filtered[i] << ' ';
	}
	std::cout << '\n';

	int result = fold(arr, size, 0, sum);
	std::cout << "fold: " << result << '\n';

	delete[] filtered;
}