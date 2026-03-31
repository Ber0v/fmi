#include "GamePlatform.h"
#include <iostream>
#include <fstream>

GamePlatform::GamePlatform()
{
	count = 0;
}

bool GamePlatform::addGame(const Game& game)
{
	if (count >= MAX_GAMES)
		return false;

	games[count++] = game;
	return true;
}

void GamePlatform::printGameByIndex(int index) const
{
	if (index < 0 || index >= count)
	{
		std::cout << "Invalid index\n";
		return;
	}

	games[index].print();
}

void GamePlatform::printAllGames() const
{
	for (int i = 0; i < count; i++)
	{
		games[i].print();
	}
}

void GamePlatform::printCheapestGame() const
{
	if (count == 0) return;

	int minIndex = 0;

	for (int i = 1; i < count; i++)
	{
		if (games[i].getPrice() < games[minIndex].getPrice())
		{
			minIndex = i;
		}
	}

	games[minIndex].print();
}

void GamePlatform::printExpensiveGame() const
{
	if (count == 0) return;

	int maxIndex = 0;

	for (int i = 1; i < count; i++)
	{
		if (games[i].getPrice() > games[maxIndex].getPrice())
		{
			maxIndex = i;
		}
	}

	games[maxIndex].print();
}

void GamePlatform::printFreeGames() const
{
	for (int i = 0; i < count; i++)
	{
		if (games[i].isFree())
		{
			games[i].print();
		}
	}
}

bool GamePlatform::removeGame(int index)
{
	if (index < 0 || index >= count)
		return false;

	for (int i = index; i < count - 1; i++)
	{
		games[i] = games[i + 1];
	}

	count--;
	return true;
}

void GamePlatform::saveToTextFile(const char* fileName) const
{
	std::ofstream out(fileName);

	if (!out.is_open())
	{
		std::cout << "File error\n";
		return;
	}

	out << count << '\n';

	for (int i = 0; i < count; i++)
	{
		out << games[i].getTitle() << '\n'
			<< games[i].getPrice() << '\n'
			<< games[i].getIsAvailable() << '\n';
	}

	out.close();
}

void GamePlatform::loadFromTextFile(const char* fileName)
{
	std::ifstream in(fileName);

	if (!in.is_open())
	{
		std::cout << "File error\n";
		return;
	}

	in >> count;
	in.ignore();

	for (int i = 0; i < count; i++)
	{
		char buffer[65];
		double price;
		bool available;

		in.getline(buffer, 65);
		in >> price >> available;
		in.ignore();

		games[i].setTitle(buffer);
		games[i].setPrice(price);
		games[i].setIsAvailable(available);
	}

	in.close();
}

void GamePlatform::saveToBinaryFile(const char* fileName) const
{
	std::ofstream out(fileName, std::ios::binary);

	if (!out.is_open())
	{
		std::cout << "File error\n";
		return;
	}

	out.write((const char*)&count, sizeof(count));
	out.write((const char*)games, sizeof(Game) * count);

	out.close();
}

void GamePlatform::loadFromBinaryFile(const char* fileName)
{
	std::ifstream in(fileName, std::ios::binary);

	if (!in.is_open())
	{
		std::cout << "File error\n";
		return;
	}

	in.read((char*)&count, sizeof(count));
	in.read((char*)games, sizeof(Game) * count);

	in.close();
}