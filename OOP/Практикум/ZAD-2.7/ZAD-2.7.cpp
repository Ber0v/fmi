#include <iostream>

using namespace std;

struct Date
{
	unsigned day : 5;
	unsigned month : 4;
	unsigned year : 12;
};

void readDate(Date& d)
{
	unsigned day;
	unsigned month;
	unsigned year;

	cout << "Den: ";
	cin >> day;

	cout << "Mesec: ";
	cin >> month;

	cout << "Godina: ";
	cin >> year;

	d.day = day;
	d.month = month;
	d.year = year;
}

void printDate(const Date& d)
{
	cout << d.day << "." << d.month << "." << d.year;
}

enum class Genre
{
	Action,
	RPG,
	Shooter,
	Strategy,
	Sports,
	Racing,
	Adventure,
	Simulation
};

const char* genreToString(Genre g)
{
	switch (g)
	{
	case Genre::Action: return "Action";
	case Genre::RPG: return "RPG";
	case Genre::Shooter: return "Shooter";
	case Genre::Strategy: return "Strategy";
	case Genre::Sports: return "Sports";
	case Genre::Racing: return "Racing";
	case Genre::Adventure: return "Adventure";
	case Genre::Simulation: return "Simulation";
	default: return "Unknown";
	}
}

void printGenreMenu()
{
	cout << "Janr\n";
	cout << "0 Action\n";
	cout << "1 RPG\n";
	cout << "2 Shooter\n";
	cout << "3 Strategy\n";
	cout << "4 Sports\n";
	cout << "5 Racing\n";
	cout << "6 Adventure\n";
	cout << "7 Simulation\n";
}

struct Game
{
	char* name;
	Date releaseDate;
	int ageRating;
	Genre genre;
	double price;
};

int cstrLen(const char* s)
{
	int n = 0;
	while (s[n] != '\0') n++;
	return n;
}

char* cstrDup(const char* s)
{
	int n = cstrLen(s);
	char* r = new (nothrow) char[n + 1];
	for (int i = 0; i < n; i++) r[i] = s[i];
	r[n] = '\0';
	return r;
}

void freeGame(Game& g)
{
	delete[] g.name;
	g.name = nullptr;
}

void readGame(Game& g)
{
	char buffer[256];

	cout << "Ime edna duma: ";
	cin >> buffer;

	g.name = cstrDup(buffer);
	if (!g.name)
	{
		cout << "404";
		return;
	}

	cout << "Release date\n";
	readDate(g.releaseDate);

	cout << "Age rating: ";
	cin >> g.ageRating;

	printGenreMenu();
	cout << "Izbor: ";
	int x;
	cin >> x;
	g.genre = (Genre)x;

	cout << "Cena: ";
	cin >> g.price;
}

void printGame(const Game& g)
{
	cout << "Ime: " << (g.name ? g.name : "") << "\n";
	cout << "Release: ";
	printDate(g.releaseDate);
	cout << "\n";
	cout << "Age rating: " << g.ageRating << "\n";
	cout << "Janr: " << genreToString(g.genre) << "\n";
	cout << "Cena: " << g.price << "\n";
}

int indexMostExpensive(const Game* arr, int n)
{
	if (n <= 0) return -1;

	int best = 0;
	for (int i = 1; i < n; i++)
	{
		if (arr[i].price > arr[best].price) best = i;
	}
	return best;
}

void printAge18Games(const Game* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i].ageRating == 18)
		{
			printGame(arr[i]);
			cout << "\n";
		}
	}
}

void printGamesByYear(const Game* arr, int n, unsigned year)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i].releaseDate.year == year)
		{
			printGame(arr[i]);
			cout << "\n";
		}
	}
}

void printGamesByGenre(const Game* arr, int n, Genre g)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i].genre == g)
		{
			printGame(arr[i]);
			cout << "\n";
		}
	}
}

void freeGamesArray(Game* arr, int n)
{
	for (int i = 0; i < n; i++) freeGame(arr[i]);
	delete[] arr;
}

int main()
{
	int n;
	cout << "N: ";
	cin >> n;

	Game* games = new (nothrow) Game[n];
	for (int i = 0; i < n; i++)
	{
		games[i].name = nullptr;
		cout << "\nGame " << (i + 1) << "\n";
		readGame(games[i]);
	}

	cout << "\nNai skupata igra\n";
	int idx = indexMostExpensive(games, n);
	if (idx != -1) printGame(games[idx]);

	cout << "\n\nIgri s age rating 18\n";
	printAge18Games(games, n);

	cout << "Godina za filtrirane: ";
	unsigned y;
	cin >> y;
	cout << "\nIgri prez " << y << "\n";
	printGamesByYear(games, n, y);

	cout << "Janr za filtrirane\n";
	printGenreMenu();
	cout << "Izbor: ";
	int gx;
	cin >> gx;
	cout << "\nIgri s janr " << genreToString((Genre)gx) << "\n";
	printGamesByGenre(games, n, (Genre)gx);

	freeGamesArray(games, n);
	return 0;
}