#include <iostream>

struct Date
{
	unsigned day : 5;
	unsigned month : 4;
	unsigned year : 12;
};

void readDate(Date& d)
{
	unsigned day;
	unsigned month;
	unsigned year;

	std::cout << "Den: ";
	std::cin >> day;

	std::cout << "Mesec: ";
	std::cin >> month;

	std::cout << "Godina: ";
	std::cin >> year;

	d.day = day;
	d.month = month;
	d.year = year;
}

void printDate(const Date& d)
{
	std::cout << d.day << "." << d.month << "." << d.year << '\n';
}

int main()
{
	Date d;

	readDate(d);

	std::cout << "Data: ";
	printDate(d);

	return 0;
}