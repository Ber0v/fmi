#include <iostream>
#include <fstream>

using namespace std;

int getSum(int i, int j)
{
	return i + j;
}

int main()
{
	ifstream file("file.dat", ios::binary);

	if (!file.is_open())
	{
		cout << "File open error";
		return -1;
	}

	file.seekg(0, ios::end);
	int size = file.tellg();

	int count = size / sizeof(int);

	file.seekg(0, ios::beg);

	int* nums = new (nothrow) int[count];
	if (nums == nullptr)
	{
		cout << "Allocation error";
		return -1;
	}

	for (int i = 0; i < count; i++)
	{
		if (!file.read((char*)&nums[i], sizeof(nums[i])))
		{
			cout << "Read error";
			delete[] nums;
			return -1;
		}
	}

	for (int i = 0; i < count; i++)
	{
		cout << nums[i] << ' ';
	}

	cout << '\n';

	if (count < 2)
	{
		cout << "Not enough numbers";
		delete[] nums;
		file.close();
		return -1;
	}

	cout << getSum(nums[0], nums[1]);

	delete[] nums;
	file.close();
}