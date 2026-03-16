#include <iostream>

void setBit(int k, unsigned char& num)
{
	num = num | (1 << k);
}

void clearBit(int k, unsigned char& num)
{
	num = num & ~(1 << k);
}

void flipBit(int k, unsigned char& num)
{
	num = num ^ (1 << k);
}

bool checkBit(int k, unsigned char& num)
{
	return (num >> k) & 1;
}

int main()
{
	unsigned char num = 5;
	setBit(2, num);
	std::cout << (unsigned)num << '\n';

	unsigned char num2 = 5;
	clearBit(2, num2);
	std::cout << (unsigned)num2 << '\n';

	unsigned char num3 = 5;
	flipBit(2, num3);
	std::cout << (unsigned)num3 << '\n';

	unsigned char num4 = 5;
	std::cout << checkBit(2, num4);
}