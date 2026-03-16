#include <iostream>
#include <fstream>
using namespace std;

void readNums(const char* fileName)
{
	ifstream file(fileName, ios::binary);

	if (!file.is_open())
	{
		cout << "File open error";
		return;
	}

	int n;
	file.read((char*)&n, sizeof(n));

	int* nums = new (nothrow)int[n];

	if (nums == nullptr)
	{
		cout << "Allocation error";
		return;
	}

	for (int i = 0; i < n; i++)
	{
		file.read((char*)&nums[i], sizeof(nums[i]));
	}

	file.close();

	for (int i = 0; i < n; i++)
	{
		cout << nums[i] << ' ';
	}
	delete[] nums;
}

int main()
{
	readNums("numbers.dat");
}