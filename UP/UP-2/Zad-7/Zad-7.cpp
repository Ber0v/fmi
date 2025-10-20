#include <iostream>

int main()
{
    char a;
    int b, c;

    switch(a)
    {
    case '+':
        std::cout << a + b;
        break;
        case '-':
        std::cout << a - b;
        break;
        case '*':
        std::cout << a * b;
        break;
        case '/':
        std::cout << a / b;
        break;
    }
}