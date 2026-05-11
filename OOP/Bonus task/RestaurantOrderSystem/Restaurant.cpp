#include "Restaurant.h"
#include <iostream>

Restaurant::Restaurant()
	: products(nullptr), count(0), capacity(0)
{
	setName("NoName");
}

Restaurant::Restaurant(const char* name, size_t capacity)
	: Restaurant()
{
	setName(name);

	this->capacity = capacity;
	if (capacity > 0)
	{
		delete[] products;
		products = new char* [capacity];
	}
}

Restaurant::Restaurant(const Restaurant& other)
	: products(nullptr), count(other.count), capacity(other.capacity)
{
	setName(other.name);

	if (capacity > 0)
	{
		products = new char* [capacity];
	}

	for (size_t i = 0; i < count; i++)
	{
		size_t len = strlen(other.products[i]);
		products[i] = new char[len + 1];
		strcpy(products[i], other.products[i]);
	}
}

Restaurant& Restaurant::operator=(const Restaurant& other)
{
	if (this == &other)
		return *this;

	free();

	setName(other.name);
	count = other.count;
	capacity = other.capacity;
	products = nullptr;

	if (capacity > 0)
	{
		products = new char* [capacity];
	}

	for (size_t i = 0; i < count; i++)
	{
		size_t len = strlen(other.products[i]);
		products[i] = new char[len + 1];
		strcpy(products[i], other.products[i]);
	}

	return *this;
}

Restaurant::~Restaurant()
{
	free();
}

void Restaurant::addProduct(const char* product)
{
}

bool Restaurant::hasProduct(const char* product) const
{
	return false;
}

int Restaurant::takeOrder(const char** orderProducts, size_t count) const
{
	return 0;
}

const char* Restaurant::getName() const
{
	return name;
}

void Restaurant::setName(const char* name)
{
	strcpy(this->name, name);
}

void Restaurant::free()
{
	for (size_t i = 0; i < count; i++)
	{
		delete[] products[i];
	}
	delete[] products;
}