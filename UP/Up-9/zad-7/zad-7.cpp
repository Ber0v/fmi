#include <iostream>

unsigned countArr(const char* arr)
{
	unsigned counter = 0;
	for (int i = 0; arr[i]; i++)
	{
		if ((arr[i] >= 'A' && arr[i] <= 'z') ||
			(arr[i] >= '0' && arr[i] <= '9'))
		{
			counter++;
		}
	}
	return counter;
}

char* remove(char* arr)
{
	int lenght = countArr(arr);
	char* newF = new char[lenght + 1] {};

	for (int i = 0, place = 0; place < lenght; i++)
	{
		if ((arr[i] >= 'A' && arr[i] <= 'z') ||
			(arr[i] >= '0' && arr[i] <= '9'))
		{
			newF[place++] = arr[i];
		}
	}

	return newF;
}

int main()
{
	char arr[] = "a!b@c#d3e$f";
	char* newArr = remove(arr);
	std::cout << newArr;
	delete[]newArr;
}