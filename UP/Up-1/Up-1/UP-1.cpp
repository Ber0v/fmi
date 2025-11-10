#include <iostream>

void drawTree();
void Zad1();
void Zad2();
void Zad3();
void Zad4();
void Zad5();
void gg();

int main()
{
    int choice;

    std::cout << "Choose which feature to release:\n";
    std::cout << "(1) drawTree\n";
    std::cout << "(2) Zad1\n";
    std::cout << "(3) Zad2\n";
    std::cout << "(4) Zad3\n";
    std::cout << "(5) Zad4\n";
    std::cout << "(6) Zad5\n";
    std::cout << "(7) gg\n";

    std::cin >> choice;

    system("cls");

    switch(choice)
    {
    case 1:
        drawTree();
        break;
    case 2:
        Zad1();
        break;
        case 3:
        Zad2();
        break;
        case 4:
        Zad3();
        break;
        case 5:
        Zad4();
        break;
        case 6:
        Zad5();
        break;
        case 7:
        gg();
        break;
    default:
        std::cout << "There is no such number";
            break;
    }
}

 void drawTree()
 {
     int n;
    std::cout << "Enter a height: ";
    std::cin >> n;

    for (int i = 1; i <= n; i++)
    {
        
        for (int j = i; j < n; j++)
        {
            std::cout << " ";
        }

        for (int j = 1; j <= (2 * i - 1); j++)
        {
            std::cout << "*";
        }

        std::cout << std::endl;
    }
 }

 void Zad1()
 {
     std::cout << "Hello World!";
 }

 void Zad2()
 {
     int a;
     int b;
     std::cin >> a;
     std::cin >> b;

     int Perimeter = 2 * (a + b);
     int Area = a * b;

     std::cout << "Perimeter: " << Perimeter;
     std::cout << "Area: " << Area;
     std::cout << "\n";
 }

 void Zad3()
 {
     double c;

     std::cin >> c;

     std::cout << c * 1.8 + 32;
 }

 void Zad4()
 {
    int a = 5;
    int b = 12;

    a = a + b;
    b = a - b;
    a = a - b;

    std::cout << a << ' ' << b << '\n';
 }

void Zad5()
{
    int a;
    
    std::cin >> a;

    std::cout << a%10 + (a%100)/10 + a/100;
}

void gg()
{
    int a;
    int b = 0;
    int c;

    std::cin >> a;

    for (int i = 0; i < 3; i++)
    {
        c = a % 10;
        b += c;
        a /= 10;
    }
    std::cout << b;
}