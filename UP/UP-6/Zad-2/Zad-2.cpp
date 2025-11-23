#include <iostream>

void countDigits(long long n, int arr[10])
{
	while (n > 0)
	{
		int i = n % 10;
		arr[i]++;
		n /= 10;
	}
}

int sumUnique(const int arr[10])
{
	int s = 0;
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] == 1)
		{
			s += i;
		}
	}
	return s;
}

int main() {
	long long n;
	std::cin >> n;

	int arr[10]{ 0 };

	countDigits(n, arr);
	std::cout << sumUnique(arr);
}
