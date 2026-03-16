#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream file("ZAD-3.1.cpp");

	if (!file.is_open())
		return -1;

	char c;

	while (file.get(c))
	{
		cout << c;
	}

	file.close();
}