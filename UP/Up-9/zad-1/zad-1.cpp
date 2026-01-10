#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << ' ';
	}
	delete[] arr;
}