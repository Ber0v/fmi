#pragma once
class Beverage
{
public:
	// konstructori
	Beverage(); // default
	Beverage(const char* name, double price, bool haveAlcohol); // parameter
	Beverage(const Beverage& other); //copy
	~Beverage(); // destr
	Beverage& operator=(const Beverage& other); //оператор=

	//metods
	void print() const;

	//getter
	const char* getName() const;
	double getPrice() const;
	bool getHaveAlcohol() const;

	//setter
	void setName(const char* name);
	void setPrice(double price);
	void setHaveAlcohol(bool Al);

private:
	char* name;
	double price;
	bool haveAlcohol;
};