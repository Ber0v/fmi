#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	long long resultBin = 0;
	long long plice = 1;
	while(n != 0)
	{
		resultBin += (n % 2) * plice;
		n /= 2;
		plice *= 10;
	}
	std::cout << "binary: " << resultBin;

	int base = 1;
	int resultTen = 0;

	while(resultBin != 0)
	{
		resultTen += (resultBin % 10) * base;
		resultBin /= 10;
		base *= 2;
	}

	std::cout << "\nNot binary: " << resultTen;
}