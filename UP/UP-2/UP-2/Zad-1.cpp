#include <iostream>

int main()
{
    int isEven = 0;
    std::cin >> isEven;

    if((isEven % 2) == 0)
    {
        std::cout << "Even";
    }
    else
    {
        std::cout << "Odd";
    }
}