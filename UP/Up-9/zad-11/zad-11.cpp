#include <iostream>
// ---------- commands ----------
bool isEnd(const char* str)
{
	return str[0] == 'E' && str[1] == 'n' && str[2] == 'd' && str[3] == '\0';
}

bool isCD(const char* str)
{
	return str[0] == 'c' && str[1] == 'd' && str[2] == '\0';
}

bool isPwd(const char* str)
{
	return str[0] == 'p' && str[1] == 'w' && str[2] == 'd' && str[3] == '\0';
}

bool startsWithDotDot(const char* str)
{
	return str[0] == '.' && str[1] == '.' && str[2] == '\0';
}

bool isFullPath(const char* str)
{
	return str[0] != '\0' && str[1] == ':' && str[2] == '/';
}

bool isRootPath(const char* str)
{
	return str[0] != '\0' && str[1] == ':' && str[2] == '/' && str[3] == '\0';
}

// ---------- helpers ----------

int myLen(const char* str)
{
	int lent = 0;
	while (str[lent++]);
	return lent - 1;
}

void copyStr(char* path, const char* arg)
{
	int i = 0;
	while (arg[i] != '\0')
	{
		path[i] = arg[i];
		i++;
	}
	path[i] = '\0';
}

void ensureTrailingSlash(char* path)
{
	int n = myLen(path);
	if (n == 0) return;
	if (path[n - 1] != '/')
	{
		path[n] = '/';
		path[n + 1] = '\0';
	}
}

bool canAppend(const char* path, const char* add, int cap)
{
	int a = myLen(path);
	int b = myLen(add);

	return a + b + 1 < cap;
}

void commandPwd(const char* path)
{
	int i = 0;
	int start = 0;

	while (true)
	{
		if (path[i] == '/' || path[i] == '\0')
		{
			for (int k = start; k < i; k++) std::cout << path[k];
			std::cout << '\n';

			if (path[i] == '\0') break;
			start = i + 1;
		}
		i++;
	}
}

void commandCd(char* path, const char* arg)
{
	ensureTrailingSlash(path);

	if (startsWithDotDot(arg))
	{
		if (isRootPath(path))
		{
			std::cout << "Error: Cannot move above root directory.\n";
			return;
		}

		int n = myLen(path);
		if (n > 0 && path[n - 1] == '/') path[n - 1] = '\0';

		n = myLen(path);
		int j = n - 1;
		while (j >= 0 && path[j] != '/') j--;

		if (j >= 0) path[j + 1] = '\0';
		ensureTrailingSlash(path);
		return;
	}

	if (isFullPath(arg))
	{
		if (myLen(arg) >= 1023)
		{
			std::cout << "Error: Path too long.\n";
			return;
		}
		copyStr(path, arg);
		ensureTrailingSlash(path);
		return;
	}

	if (!canAppend(path, arg, 1024))
	{
		std::cout << "Error: Path too long.\n";
		return;
	}

	int p = myLen(path);
	int i = 0;
	while (arg[i] != '\0')
	{
		path[p++] = arg[i++];
	}
	path[p++] = '/';
	path[p] = '\0';
}

int main()
{
	char path[1024] = "C:/";
	char input[1024];

	std::cout << '\n' << path << "> ";
	std::cin >> input;
	while (!isEnd(input))
	{
		if (isCD(input))
		{
			std::cin >> input;
			commandCd(path, input);
		}
		else if (isPwd(input))
		{
			commandPwd(path);
		}
		else
		{
			std::cout << "What is that Bro??\n";
		}
		std::cout << '\n' << path << "> ";
		std::cin >> input;
	}
}