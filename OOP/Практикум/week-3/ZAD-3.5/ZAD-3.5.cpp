#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int getWordCount(const char* word, const char* fileName)
{
	ifstream file(fileName);

	if (!file.is_open())
		return -1;

	int count = 0;
	char word1[256];

	while (file >> word1)
	{
		if (strcmp(word, word1) == 0)
			count++;
	}

	file.close();
	return count;
}

int main()
{
	char word[] = "virtual";
	char path[] = "testFile.txt";
	int result = getWordCount(word, path);

	if (result == -1)
		cout << "File not opened";
	else
		cout << "Count: " << result;
}