#include "Game.h"
#include <iostream>
#include <cstring>
#include <exception>

Game::Game()
{
	strcpy(title, "NoTitle");
	price = 0.0;
	isAvailable = false;
}

Game::Game(const char* title, double price, bool isAvailable)
	: price(price), isAvailable(isAvailable)
{
	setTitle(title);
}

Game::Game(const Game& g)
{
	strcpy(title, g.title);
	price = g.price;
	isAvailable = g.isAvailable;
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
		throw std::exception("Invalid title\n");
	}

	if (strlen(title) >= 64)
	{
		throw std::exception("Title too long\n");
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
