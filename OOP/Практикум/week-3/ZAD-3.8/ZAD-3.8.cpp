#include <iostream>
#include <fstream>

using namespace std;

void replaceChar(const char* fileName, char target, char replacement)
{
	ifstream inFile(fileName);
	ofstream outFile("temp.txt");

	if (!inFile.is_open() || !outFile.is_open())
	{
		cout << "File not opened";
		return;
	}

	char ch;

	while (inFile.get(ch))
	{
		if (ch == target)
			outFile.put(replacement);
		else
			outFile.put(ch);
	}

	inFile.close();
	outFile.close();

	remove(fileName);
	rename("temp.txt", fileName);
}

int main()
{
	replaceChar("text.txt", 'a', 'x');
}