#include <iostream>

int main()
{
    int a;
    std::cin >> a;

    if((a % 3 == 0) && (a % 5 == 0))
    {
        std::cout << "FizzBuzz";
    }
    else if (a % 3 == 0)
    {
        std::cout << "Fizz";
    }
    else if (a % 5 == 0)
    {
        std::cout << "Buzz";
    }
    else
    {
        std::cout << a;
    }
}

