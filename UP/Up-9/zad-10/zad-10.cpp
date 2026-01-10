#include <iostream>

unsigned countArr(const char* arr, int place)
{
	unsigned counter = 0;
	for (int i = place; ; i++)
	{
		if (arr[i] == '/' || arr[i] == '\0') break;
		counter++;
	}
	return counter;
}

int counterFolders(const char* path)
{
	int i = 0;
	int folders = 1;
	while (path[i++])
	{
		if (path[i] == '/') folders++;
	}
	return folders;
}

char* Folder(const char* path, int& place)
{
	int sibols = countArr(path, place);
	char* newF = new char[sibols + 1] {};
	for (int i = 0; i < sibols; i++)
	{
		newF[i] = path[place++];
	}
	place++;
	return newF;
}

int main()
{
	char path[1024] = "C:/Windows/System32/notepad.exe";
	//std::cin >> path;
	int folders = counterFolders(path);

	int place = 0;

	char** pathMatrix = new char* [folders];
	for (int i = 0; i < folders; i++)
	{
		pathMatrix[i] = Folder(path, place);
	}

	for (int i = 0; i < folders; i++)
	{
		std::cout << pathMatrix[i] << '\n';
	}
	std::cout << "total: " << folders << '\n';

}