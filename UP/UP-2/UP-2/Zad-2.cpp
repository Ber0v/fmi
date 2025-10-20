#include <iostream>

int main()
{
    int a;
    int b;
    int c;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;

    if(a+b>c && a+c>b && b+c>a)
    {
        std::cout << "Invalid triangle!";
    }
    else
        std::cout << "Valid triangle!";
}