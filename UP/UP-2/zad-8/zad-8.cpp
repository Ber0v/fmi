#include <iostream>

int main() {
    double x, y;            
    double x1, y1, x2, y2;
    std::cin >> x >> y >> x1 >> y1 >> x2 >> y2;

    if (x > x1 && x < x2 && y > y1 && y < y2 ||
        x > x2 && x < x1 && y > y2 && y < y1 ||
        x > x1 && x < x2 && y > y2 && y < y1 ||
        x > x2 && x < x1 && y > y1 && y < y2)
        std::cout << "Inside";
    else if ((x >= x1 && x <= x2 && y >= y1 && y <= y2 ||
              x >= x2 && x <= x1 && y >= y2 && y <= y1) &&
             (x == x1 || x == x2 || y == y1 || y == y2))
        std::cout << "On the border";
    else
        std::cout << "Outside";

    return 0;
}
