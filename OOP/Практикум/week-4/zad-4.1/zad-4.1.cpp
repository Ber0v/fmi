#include <iostream>
#include <fstream>

using namespace std;

void writeNums(int n, int* nums, const char* fileName)
{
	ofstream file(fileName, ios::binary);

	if (!file.is_open())
	{
		cout << "Error";
		return;
	}

	file.write((const char*)&n, sizeof(n));


	for (int i = 0; i < n; i++)
	{
		file.write((const char*)&nums[i], sizeof(nums[i]));
	}

	if (!file.good())
	{
		cout << "Write error";
		return;
	}

	file.close();
}

int main()
{
	int n;
	cin >> n;

	int* nums = new (nothrow) int[n];

	if (nums == nullptr)
	{
		cout << "Allocation error";
		return 1;
	}

	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	writeNums(n, nums, "numbers.dat");

	delete[] nums;
}