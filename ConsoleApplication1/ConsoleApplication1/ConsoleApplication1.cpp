#include<iostream>

int counter(const char* arr)
{
	int count = 0;
	while (arr[count++]);
	return count - 1;
}

int main()
{
	char text[] = "hello world";
	char pattern[] = "ll";
	int count = 0;
	int patternCount = counter(pattern);
	int textCount = counter(text);

	for (int i = 0; i < textCount; i++)
	{
		if (text[i] == pattern[0] && text[i + 1] == pattern[1])count++;
	}
	std::cout << count;
}