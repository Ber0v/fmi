#include <iostream>
#include <fstream>

using namespace std;

int getWordCount(const char* fileName)
{
	ifstream file(fileName);

	if (!file.is_open())
		return -1;

	int count = 0;
	char word[256];

	while (file >> word)
	{
		count++;
	}

	file.close();
	return count;
}

int main()
{
	char path[] = "gogo.txt";

	cout << getWordCount(path);
}