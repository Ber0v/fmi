#include <iostream>

int main()
{
    double x,y,r;
    std::cin >> x >> y >> r;

    double distamcesquared = x * x + y * y;
    double radioussquared = r * r;

    if(distamcesquared < radioussquared)
    {
        std::cout << "Inside";
    }
    else if(distamcesquared == radioussquared)
    {
        std::cout <<"On the border";
    }
    else
    {
        std::cout <<"Outside";
    }
}