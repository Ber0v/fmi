#include <iostream>

bool isUpper(char a)
{
    return a >= 'A' && a <= 'Z';
}

int main()
{
    char a;
    std::cin >> a;
    
    std::cout << std::boolalpha << isUpper(a);
}