#include <iostream>

int ExtentNum(long n)
{
    int res = 0;
    while(n != 0)
    {
        res++;
        n /= 10;
    }

    return res;
}

int main()
{
    long num;
    std::cin >> num;

    std::cout << ExtentNum(num);
}