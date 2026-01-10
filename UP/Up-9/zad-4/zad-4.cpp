#include <iostream>

unsigned* counter(const char* str)
{
	unsigned* murziMe = new unsigned[128] {};

	for (int i = 0; str[i]; i++)
	{
		murziMe[(unsigned char)str[i]]++;
	}
	return murziMe;
}

int main()
{
	char input[] = "aabs1WWr125#$!%^";

	unsigned* res = counter(input);

	for (int i = 32; i <= 126; i++)
	{
		if (res[i] > 0)
		{
			std::cout << (char)i << " - " << res[i] << '\n';
		}
	}

	delete[] res;
}