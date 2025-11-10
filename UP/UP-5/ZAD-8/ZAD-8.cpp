#include <iostream>

int divisionNum(int a, int b)
{
    return a / b;
}
double divisionNum(double a, double b)
{
    return a / b;
}

int main()
{
    int a, b;
    std::cin >> a >> b;

    std::cout << divisionNum(5.0, 3.0);
}