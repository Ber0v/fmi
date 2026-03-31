#pragma once
#include "Game.h"

class GamePlatform
{
public:
	GamePlatform();

	// methods
	bool addGame(const Game& game);
	void printGameByIndex(int index) const;
	void printAllGames() const;

	void printCheapestGame() const;
	void printExpensiveGame() const;
	void printFreeGames() const;

	bool removeGame(int index);

	void saveToTextFile(const char* fileName) const;
	void loadFromTextFile(const char* fileName);

	void saveToBinaryFile(const char* fileName) const;
	void loadFromBinaryFile(const char* fileName);

private:
	static const int MAX_GAMES = 32;

	Game games[MAX_GAMES];
	int count;
};