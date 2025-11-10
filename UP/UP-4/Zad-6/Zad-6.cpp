#include <iostream>

int main()
{
	int chas = 0;
	int minuti = 0;
	while (chas != 23 && minuti != 59)
	{
		minuti++;
		std::cout << chas << ':' << minuti << '\n';

		if(minuti == 59)
		{
			chas++;
			minuti = 0;
		}
	}
}