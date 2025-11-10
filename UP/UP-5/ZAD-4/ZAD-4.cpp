#include <iostream>

int Rosult(int a, int b, char Op)
{
    switch(Op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '/':
        return a / b;
    case '*':
        return a * b;
    }
}

int main()
{
    int a, b;
    char Operator;

    std::cin >> a >> b >> Operator;

    std::cout << Rosult(a, b, Operator);
}