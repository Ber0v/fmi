#include <iostream>

int main()
{
    char a;
    std::cin >> a;
    if (a >= 'a' && a <= 'z')
    {
        std::cout << "Lowercase";
    }
    else
        std::cout << "Uppercase";
}