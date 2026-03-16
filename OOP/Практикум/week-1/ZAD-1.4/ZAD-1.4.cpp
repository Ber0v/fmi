#include <iostream>
using namespace std;

int fold(const int* arr, int size, int n, int (*foo)(int, int))
{
	if (!arr || size <= 0 || !foo) return n;

	int acc = n;

	for (int i = 0; i < size; i++)
	{
		int previous = acc;
		acc = foo(acc, arr[i]);

		cout << previous << " + arr[" << i << "] = " << acc << "\n";
	}

	return acc;
}

int sum(int a, int b)
{
	return a + b;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };

	fold(arr, 5, 0, sum);
}