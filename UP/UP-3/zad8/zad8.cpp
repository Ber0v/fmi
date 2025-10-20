#include <iostream>

int main()
{
    int n, num;
    std::cin >> n;
    bool oddNum = true;

    for (int i = 0; i < n; i++)
    {
        std::cin >> num;
        if(num % 2 == 0)
        {
            oddNum = false;
        }
    }
    if(oddNum)
    {
        std::cout << "true";
    }
    else
    {
        std::cout << "fouse";
    }
}