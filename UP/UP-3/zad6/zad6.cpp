#include <iostream>

int main()
{
    int n, y;
    std::cin >> n >> y;
    int sum1 = 0;
    int sum2 = 0;

    while(n!=0)
    {
        sum1 += n % 10;
        n /= 10;
    }
    while(y!=0)
    {
        sum2 += y % 10;
        y /= 10;
    }

    if(sum1 == sum2)
    {
        std::cout << "true";
    }
    else
    {
        std::cout << "fouse";
    }
}