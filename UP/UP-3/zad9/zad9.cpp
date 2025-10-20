#include <iostream>

int main()
{
	int n, original, reversed = 0;
    std::cin >> n;
    original = n;

    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }

    std::cout << (original == reversed ? "true" : "false");
}