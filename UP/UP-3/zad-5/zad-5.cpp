#include <iostream>

int main()
{
    int n, y;
    std::cin >> n >> y;

    if(n<=y)
    {
        for (int i = n; i >= 1; i--)
        {
            if ((n % i) == 0 && (y % i) == 0)
            {
                std::cout << i;
                return 0;
            }
        }
    }
    else
    {
        for (int i = y; i >= 1; i--)
        {
            if ((n % i) == 0 && (y % i) == 0)
            {
                std::cout << i;
                return 0;
            }
        }
    }
}