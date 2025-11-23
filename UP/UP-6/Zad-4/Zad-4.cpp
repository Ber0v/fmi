#include <iostream>

bool perm(int arr1[], int arr2[], int count)
{
	for (int i = 0; i < count; i++)
	{
		bool found = false;
		for (int j = 0; j < count; j++)
		{
			if (arr1[i] == arr2[j])
			{
				found = true;
				break;
			}
		}
		if (!found) return false;
	}
	return true;
}

void readArray(int arr[32], int count)
{
	for (int i = 0; i < count; i++)
	{
		std::cin >> arr[i];
	}
}

int main()
{
	int n;
	std::cin >> n;

	int arr1[32];
	readArray(arr1, n);

	int arr2[32];
	readArray(arr2, n);

	std::cout << std::boolalpha << perm(arr1, arr2, n);
}