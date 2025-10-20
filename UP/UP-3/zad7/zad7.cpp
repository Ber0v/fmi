#include <iostream>

int main()
{
    int secretNum;
    int guessedNum = 0;
    std::cin >> secretNum;
    
    while(true)
    {
        std::cin >> guessedNum;

        if(guessedNum > secretNum)
        {
            std::cout << "Go lower\n";
        }
        else if (guessedNum < secretNum)
        {
            std::cout << "Go higher\n";
        }
        else
        {
            std::cout << "Congratulations! You guessed the number.";
            return 0;
        }
    }
}