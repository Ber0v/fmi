#include <iostream>

template<typename T>
void reverse(T& a, T& b)
{
	T c = b;
	b = a;
	a = c;
}

int main()
{
	int a = 4;
	int b = 5;
	std::cout << "a: " << a << " b: " << b << '\n';
	reverse(a, b);
	std::cout << "a: " << a << " b: " << b;
}