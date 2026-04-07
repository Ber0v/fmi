#pragma once
class Product
{
public:

	Product();
	Product(const char* name, const char* description, double price, bool isValid);
	Product(const Product& other);
	Product& operator=(const Product& other);
	~Product();

	//method
	void printProduct() const;
	bool canBuy(float availableMoney) const;

	// getter
	const char* getName() const;
	const char* getDescription() const;
	double getPrice() const;
	bool getIsValid() const;

	//setter
	void setName(const char* name);
	void setDescription(const char* description);
	void setPrice(double price);
	void setIsValid(bool isValid);
private:
	void clear();
private:
	char* name;
	char* description;
	double price;
	bool isValid;;
};