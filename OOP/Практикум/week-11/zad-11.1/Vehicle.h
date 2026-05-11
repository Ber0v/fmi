#pragma once

class Vehicle
{
public:
	Vehicle(const char* mark = "NoMark", unsigned year = 0, unsigned maxSpeed = 0);
	Vehicle(const Vehicle& other);
	Vehicle& operator=(const Vehicle& other);
	~Vehicle();

	//getter
	const char* getMark()const { return mark; };
	unsigned getYear()const { return year; };
	unsigned getMaxSpeed()const { return maxSpeed; };

	//setter
	void setMark(const char* mark);

private:
	char* mark;
	unsigned year;
	unsigned maxSpeed;
};