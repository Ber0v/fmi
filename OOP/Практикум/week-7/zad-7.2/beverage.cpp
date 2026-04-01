#include "beverage.h"
#include <iostream>
#include <cstring>

Beverage::Beverage()
	:name(nullptr), price(0), haveAlcohol(false)
{
	setName("NoName");
}

Beverage::Beverage(const char* name, double price, bool haveAlcohol)
	: name(nullptr), price(0), haveAlcohol(haveAlcohol)
{
	setName(name);
	setPrice(price);
}

Beverage::Beverage(const Beverage& other)
	:name(nullptr), price(other.price), haveAlcohol(other.haveAlcohol)
{
	setName(other.name);
}

Beverage::~Beverage()
{
	delete[] name;
	name = nullptr;
}

Beverage& Beverage::operator=(const Beverage& other)
{
	if (this != &other)
	{
		setName(other.name);
		price = other.price;
		haveAlcohol = other.haveAlcohol;
	}
	return *this;
}

void Beverage::print() const
{
	std::cout << "name:" << name << "\n"
		<< "price: " << price << "\n"
		<< "Alcohol: " << (haveAlcohol ? "Yes" : "No");
}

const char* Beverage::getName() const
{
	return name;
}

double Beverage::getPrice() const
{
	return price;
}

bool Beverage::getHaveAlcohol() const
{
	return haveAlcohol;
}

void Beverage::setName(const char* name)
{
	if (!name)
		return;

	delete[] this->name;

	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy(this->name, name);
}

void Beverage::setPrice(double price)
{
	if (price >= 0.0)
		this->price = price;
	else
		std::cout << "Invalid price\n";
}

void Beverage::setHaveAlcohol(bool Al)
{
	haveAlcohol = Al;
}
