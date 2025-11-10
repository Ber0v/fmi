#include <iostream>

int Result(int a, int b, int c)
{
    return a + b + c;
}

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;

    std::cout << Result(a, b, c)/3;
}