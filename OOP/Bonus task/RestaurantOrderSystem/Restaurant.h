#pragma once
class Restaurant
{
public:
	Restaurant();
	Restaurant(const char* name, size_t capacity);
	Restaurant(const Restaurant& other);
	Restaurant& operator=(const Restaurant& other);
	~Restaurant();

	void addProduct(const char* product);
	bool hasProduct(const char* product) const;
	int takeOrder(const char** orderProducts, size_t count) const;

	const char* getName() const;

private:
	void setName(const char* name);
	void free();

private:
	char name[25];
	char** products;
	size_t count;
	size_t capacity;
};