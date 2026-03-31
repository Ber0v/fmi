#include "Game.h"
#include <iostream>
#include <cstring>

Game::Game()
{
	title[0] = '\0';
	price = 0.0;
	isAvailable = false;
}

void Game::print() const
{
	std::cout << "Title: " << title
		<< ", Price: " << price
		<< ", Available: " << (isAvailable ? "Yes" : "No") << '\n';
}

bool Game::isFree() const
{
	return price <= 0.0;
}

const char* Game::getTitle() const
{
	return title;
}

double Game::getPrice() const
{
	return price;
}

bool Game::getIsAvailable() const
{
	return isAvailable;
}

void Game::setTitle(const char* title)
{
	if (!title)
	{
		std::cout << "Invalid title\n";
		return;
	}

	if (strlen(title) >= 64)
	{
		std::cout << "Title too long\n";
		return;
	}

	strcpy(this->title, title);
}

void Game::setPrice(double price)
{
	if (price >= 0.0)
		this->price = price;
	else
		std::cout << "Invalid price\n";
}

void Game::setIsAvailable(bool available)
{
	this->isAvailable = available;
}
