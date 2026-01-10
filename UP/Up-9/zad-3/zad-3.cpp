#include <iostream>
int arrLength(const char* fileName)
{
	int i = 0;
	while (fileName[i] != '\0')i++;
	return i;
}

char* concatArr(const char* arr1, const char* arr2)
{
	int length1 = arrLength(arr1);
	int length2 = arrLength(arr2);
	char* newF = new char[length1 + length2 + 1] {};

	for (int i = 0; i < length1; i++)
	{
		newF[i] = arr1[i];
	}
	for (int i = 0; i < length2; i++)
	{
		newF[length1++] = arr2[i];
	}
	return newF;
}

int main()
{
	char arr1[] = "sheise";
	char arr2[] = "isedem";


	char* concat = concatArr(arr1, arr2);

	std::cout << concat;
	delete[] concat;
}