#include <iostream>

template < typename T>
T sum(T a, T b)
{
	return a + b;
}

int main()
{
	std::cout << sum(1, 4) << '\n';
	std::cout << sum(1.3, 4.2) << '\n';
	std::cout << sum('a', 'a');
}