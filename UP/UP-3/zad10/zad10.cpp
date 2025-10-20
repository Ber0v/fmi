#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	int a = 0, b = 1, next = 0;

    for (int i = 0; i < n; i++) {
        std::cout << a << " ";
        next = a + b;
        a = b;
        b = next;
    }
}