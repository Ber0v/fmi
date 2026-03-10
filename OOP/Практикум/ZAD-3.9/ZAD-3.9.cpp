#include <iostream>
#include <fstream>

using namespace std;

void concatFiles(const char* files[], int count, const char* outputFile)
{
	ofstream out(outputFile);

	if (!out.is_open())
	{
		cout << "Output file not opened";
		return;
	}

	for (int i = 0; i < count; i++)
	{
		ifstream in(files[i]);

		if (!in.is_open())
		{
			cout << "Cannot open " << files[i] << endl;
			continue;
		}

		char ch;

		while (in.get(ch))
			out.put(ch);

		in.close();
	}

	out.close();
}

int main()
{
	const char* files[] =
	{
		"file1.txt",
		"file2.txt",
		"file3.txt"
	};

	concatFiles(files, 3, "result.txt");
}