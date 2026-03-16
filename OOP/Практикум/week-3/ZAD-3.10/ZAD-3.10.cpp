#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void grep(const char* fileName, const char* word)
{
	ifstream file(fileName);

	if (!file.is_open())
	{
		cout << "File not opened";
		return;
	}

	char line[1024];
	int lineNumber = 1;

	while (file.getline(line, 1024))
	{
		if (strstr(line, word) != nullptr)
		{
			cout << lineNumber << ": " << line << endl;
		}

		lineNumber++;
	}

	file.close();
}

int main()
{
	grep("text.txt", "cat");
}