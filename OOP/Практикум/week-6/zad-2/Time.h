#pragma once
class Time
{
public:
	Time();

	// Methods
	void PrintTime() const;
	void NextSecond();
	void NextMinutes();
	void NextHour();
	bool isItNightTime() const;

	// getters
	short getSecond() const;
	short getMinutes() const;
	short getHour() const;

	// setters
	void setSecond(short s);
	void setMinutes(short m);
	void setHour(short h);

private:
	unsigned short second;
	unsigned short minutes;
	unsigned short hour;
};