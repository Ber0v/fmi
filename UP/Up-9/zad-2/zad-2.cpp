#include <iostream>
char* coppyarr(char* fileName, int lenhgt)
{
	char* str = new char[lenhgt];
	for (int i = 0; i < lenhgt; i++)
	{
		str[i] = fileName[i];
	}

	return str;
}

int arrLength(const char* fileName)
{
	int i = 0;
	while (fileName[i] != '\0')i++;
	return i;
}

void changeName(char*& newF, const char* newName)
{
	int length = arrLength(newF);
	int newlength = arrLength(newName);

	int spot = 0;
	for (int i = length; i >= 0; i--)
	{
		if (newF[i] == '.')
		{
			spot = i;
			break;
		}
	}

	int len = length - spot;
	char* afterDot = new char[len + 1] {};
	for (int i = 0; i < len; i++)
	{
		afterDot[i] = newF[spot + i];
	}

	delete[] newF;
	newF = new char[newlength + len + 1] {};
	for (int i = 0; i < newlength; i++)
	{
		newF[i] = newName[i];
	}
	for (int j = 0, i = newlength; i < len + newlength; i++, j++)
	{
		newF[i] = afterDot[j];
	}
	delete[] afterDot;
}

int main()
{
	char fileName[100];
	char newName[100];
	std::cin >> fileName;
	char* newF = coppyarr(fileName, arrLength(fileName) + 1);
	std::cin >> newName;

	changeName(newF, newName);

	std::cout << newF;
	delete[] newF;
}