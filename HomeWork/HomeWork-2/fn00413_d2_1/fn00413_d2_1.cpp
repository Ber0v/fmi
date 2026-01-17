/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2025/2026
*
* @author Alexander Berov
* @idnumber 4MI0700413
* @task 1
* @compiler VC
*
*/

#include <iostream>

int strLen(const char* string)
{
	int len = 0;
	while (string[len] != '\0') ++len;

	return len;
}

bool isLowerLatin(const char* string)
{
	for (int i = 0; string[i] != '\0'; ++i)
	{
		if (string[i] < 'a' || string[i] > 'z') return false;
	}

	return true;
}

char* makePalindrome(const char* str1, const char* str2)
{
	if ((!str1 || !str2) || (!isLowerLatin(str1) || !isLowerLatin(str2)))
	{
		return nullptr;
	}

	int len1 = strLen(str1);
	int len2 = strLen(str2);
	int totalLen = len1 + len2;

	int cnt[26] = {};

	for (int i = 0; i < len1; ++i)
	{
		cnt[str1[i] - 'a']++;
	}
	for (int i = 0; i < len2; ++i)
	{
		cnt[str2[i] - 'a']++;
	}

	int oddCount = 0;
	int oddIndex = -1;
	for (int i = 0; i < 26; ++i)
	{
		if (cnt[i] % 2 != 0)
		{
			oddCount++;
			oddIndex = i;
		}
	}

	if (oddCount > 1)
	{
		return nullptr;
	}
	if ((oddCount == 1 && (totalLen % 2 == 0)) ||
		(oddCount == 0 && (totalLen % 2 != 0)))
	{
		return nullptr;
	}

	char* res = new char[totalLen + 1] {};

	int left = 0;
	int right = totalLen - 1;

	for (int i = 0; i < 26; ++i)
	{
		while (cnt[i] >= 2)
		{
			res[left++] = char('a' + i);
			res[right--] = char('a' + i);
			cnt[i] -= 2;
		}
	}

	if (oddIndex != -1)
		res[left] = char('a' + oddIndex);

	return res;
}

int main()
{
	char str1[101];
	char str2[101];

	std::cin >> str1 >> str2;

	char* palindrom = makePalindrome(str1, str2);

	if (!palindrom)
	{
		std::cout << "nullptr";
		return 0;
	}

	std::cout << palindrom;
	delete[] palindrom;
}