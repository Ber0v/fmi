#pragma once
class Game
{
public:
	Game();

	//metods
	void print() const;
	bool isFree() const;

	//getter
	const char* getTitle() const;
	double getPrice() const;
	bool getIsAvailable() const;

	//setter
	void setTitle(const char* title);
	void setPrice(double price);
	void setIsAvailable(bool available);

private:
	char title[64];
	double price;
	bool isAvailable;
};