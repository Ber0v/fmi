#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void replace(const char* fileName, const char* newFileName, const char* find, const char* replace)
{
	ifstream file(fileName);
	ofstream newFile(newFileName);

	if (!file.is_open() && !newFile.is_open())
		cout << "File not opened";

	char word[256];

	while (file >> word)
	{
		if (strcmp(word, find) == 0)
		{
			newFile << replace << " ";

			if (!newFile)
			{
				cout << "Write error\n";
				return;
			}
			continue;
		}
		newFile << word << " ";

		if (!newFile)
		{
			cout << "Write error\n";
			return;
		}
	}

	file.close();
	newFile.close();
}

int main()
{
	replace("sometext.txt", "somecooltext.txt", "geometriq", "OOP");
}