#include <iostream>
#include <fstream>
using namespace std;

int getLineCount(const char* fileName)
{
	ifstream file(fileName);

	if (!file.is_open())
		return -1;

	int count = 1;
	char c;

	while (file.get(c))
	{
		if (c == '\n')
			count++;
	}

	file.close();
	return count;
}

int main()
{
	char path[] = "gogo.txt";

	cout << getLineCount(path);
}