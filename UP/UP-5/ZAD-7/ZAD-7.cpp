#include <iostream>

int lengthNum(long n)
{
    int res = 0;
    while(n != 0)
    {
        res++;
        n /= 10;
    }

    return res;
}

int multiplication(int a, int length)
{
    for (int i = 0; i < length; i++)
    {
        a *= 10;
    }
    return a;
}

int main()
{
    int a, b;
    std::cin >> a >> b;

    int length = lengthNum(b);
    std::cout << multiplication(a,length) + b;
}