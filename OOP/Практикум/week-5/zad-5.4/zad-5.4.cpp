#include <iostream>

template<typename T, typename U, typename K>
void print(const T& a, const U& b, const K& c)
{
	std::cout << a << ' ' << b << ' ' << c << std::endl;;
}

int main()
{
	print('a', 10, 5);
	print(20, 1.0, "Grass");
	print(8, "YAY", 8);
}