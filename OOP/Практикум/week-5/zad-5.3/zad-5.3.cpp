#include <iostream>

template <typename T>
void print(const T* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		std::cout << arr[i];
	}
}

template <>
void print(const char* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		std::cout << arr[i];
	}
}

int main()
{
	int hi[5] = { 1 };
	print(hi, 5);
	char hiq[5] = "zad";
	print(hiq, 5);
}