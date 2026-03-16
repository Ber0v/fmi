#include <iostream>
using namespace std;

enum Suit
{
	Clubs = 1,
	Hearts,
	Diamonds,
	Spades
};

enum Rank
{
	Two = 2, Three, Four, Five, Six, Seven,
	Eight, Nine, Ten,
	Jack, Queen, King, Ace
};

void print(const char* word)
{
	cout << word;
}

int main()
{
	int suitInput, rankInput;
	cin >> suitInput >> rankInput;

	Suit suit = static_cast<Suit>(suitInput);
	Rank rank = static_cast<Rank>(rankInput);

	switch (rank)
	{
	case Jack:  print("Jack"); break;
	case Queen: print("Queen"); break;
	case King:  print("King"); break;
	case Ace:   print("Ace"); break;
	default:    cout << rankInput;
	}

	print(" of ");

	switch (suit)
	{
	case Clubs:    print("Clubs"); break;
	case Hearts:   print("Hearts"); break;
	case Diamonds: print("Diamonds"); break;
	case Spades:   print("Spades"); break;
	default:    cout << suitInput;
	}

	return 0;
}