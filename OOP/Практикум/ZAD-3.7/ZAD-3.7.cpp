#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void compareFiles(const char* fileName1, const char* fileName2)
{
	ifstream file1(fileName1);
	ifstream file2(fileName2);

	if (!file1.is_open() || !file2.is_open())
	{
		cout << "File not opened";
		return;
	}

	char line1[1024];
	char line2[1024];

	int lineNumber = 1;

	while (file1.getline(line1, 1024) && file2.getline(line2, 1024))
	{
		if (strcmp(line1, line2) != 0)
		{
			cout << "Mismatch on line " << lineNumber << ":\n";
			cout << line1 << endl;
			cout << line2 << endl;
			return;
		}

		lineNumber++;
	}

	cout << "Files are identical";

	file1.close();
	file2.close();
}

int main()
{
	compareFiles("file1.txt", "file2.txt");
}