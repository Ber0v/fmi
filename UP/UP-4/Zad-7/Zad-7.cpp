#include <iostream>

int main()
{
    int n, x, y;

    std::cin >> n >> x >> y;

	for (int i = n; i > 0; i--)
	{
		std::cout << i;
		if (i == y)
		{
			for (int j = 1; j < n; j++)
			{
				if(j == x)
				{
					std::cout << '*';
					break;
				}
				std::cout << " ";	
			}
		}
		std::cout << '\n';
	}
	for (int i = 0; i <= n; i++)
	{
		std::cout << i;
	}
}