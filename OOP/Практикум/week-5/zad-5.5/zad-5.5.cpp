#include <iostream>

template<typename T>
void print(const T* arr, int len, T pattern)
{
	for (int i = 0; i < len; i++)
	{
		if (arr[i] == pattern)
		{
			std::cout << "YAY";
			return;
		}
	}
	std::cout << "SAD";
}

int main()
{
	print("arr", 4, 'a');
}