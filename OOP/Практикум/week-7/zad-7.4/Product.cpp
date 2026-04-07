#pragma warning(disable:4996)
#include <iostream>
#include "Product.h"
#include <cstring>

Product::Product()
	:price(0), isValid(false)
{
	setName("NoName");
	setDescription("settaq");
}

Product::Product(const char* name, const char* description, double price, bool isValid)
	: price(price), isValid(isValid)
{
	setName(name);
	setDescription(description);
}

Product::Product(const Product& other)
{
	setName(other.name);
	setDescription(other.description);
	price = other.price;
	isValid = other.isValid;
}

Product& Product::operator=(const Product& other)
{
	if (this != &other) {
		clear();
		setName(other.name);
		setDescription(other.description);
		price = other.price;
		isValid = other.isValid;
	}
	return *this;
}

Product::~Product()
{
	clear();
}

void Product::printProduct() const
{
	std::cout << "name: " << name << '\n'
		<< "description: " << description << '\n'
		<< "price: " << price << '\n'
		<< "isValid: " << (isValid ? "Yes" : "No") << '\n';
}

bool Product::canBuy(float availableMoney) const
{
	return isValid && availableMoney >= isValid;
}

const char* Product::getName() const
{
	return name;
}

const char* Product::getDescription() const
{
	return description;
}

double Product::getPrice() const
{
	return price;
}

bool Product::getIsValid() const
{
	return isValid;
}

void Product::setName(const char* name)
{
	if (!name) name = "";
	int count = strlen(name);
	this->name = new char[count + 1];
	strcpy(this->name, name);
}

void Product::setDescription(const char* description)
{
	if (!description) description = "";
	int count = strlen(description);
	this->description = new char[count + 1];
	strcpy(this->description, description);
}

void Product::setPrice(double price)
{
	this->price = price;
}

void Product::setIsValid(bool isValid)
{
	this->isValid = isValid;
}

void Product::clear()
{
	delete[] name;
	name = nullptr;
	delete[] description;
	description = nullptr;
}
