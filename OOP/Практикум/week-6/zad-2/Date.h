#pragma once
class Date
{
public:
	Date();

	// Methods
	void PrintDate() const;
	void nextDay();
	void nextMonth();
	void nextYear();
	bool isSummerVacation() const;

	// getters
	short getDay() const;
	short getMonth() const;
	int getYear() const;

	// setters
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);

private:
	unsigned short day;
	unsigned short month;
	unsigned int year;
};