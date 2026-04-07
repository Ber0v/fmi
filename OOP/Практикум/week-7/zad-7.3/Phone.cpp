#include "Phone.h"
#include <iostream>
#include <cstring>

Phone::Phone()
	:model(nullptr), batteryLevel(100), OSversion(1), soundLevel(0)
{
	setModel("Unknown");

}

Phone::Phone(const char* model, unsigned batteryLevel, unsigned OSversion)
	: model(nullptr), batteryLevel(batteryLevel <= 100 ? batteryLevel : 100),
	OSversion(OSversion > 0 ? OSversion : 1), soundLevel(0)
{
	setModel(model);
}
Phone::Phone(const Phone& other)
	: model(nullptr), batteryLevel(other.batteryLevel),
	OSversion(other.OSversion), soundLevel(other.soundLevel)
{
	setModel(other.model);
}

Phone::~Phone()
{
	delete[] model;
}

Phone& Phone::operator=(const Phone& other)
{
	if (this != &other)
	{
		setModel(other.model);
		batteryLevel = other.batteryLevel;
		OSversion = other.OSversion;
		soundLevel = other.soundLevel;
	}
	return *this;
}

void Phone::printPhone() const
{
	std::cout << "----- PHONE INFO -----\n";
	std::cout << "Model: " << model << '\n';
	std::cout << "Battery: " << batteryLevel << "%\n";
	std::cout << "OS version: " << OSversion << '\n';
	std::cout << "Sound level: " << soundLevel << "/10\n";
	std::cout << "----------------------\n";
}

void Phone::watchReels(int min)
{
	if (batteryLevel == 0 || min <= 0) return;

	if ((unsigned)min >= batteryLevel)
		batteryLevel = 0;
	else
		batteryLevel -= min;
}

void Phone::playClash(int min)
{
	if (batteryLevel == 0 || min <= 0) return;

	unsigned needed = min * 3;
	if (needed >= batteryLevel)
		batteryLevel = 0;
	else
		batteryLevel -= needed;
}

void Phone::takePhoto()
{
	if (batteryLevel == 0) return;
	batteryLevel--;
}

void Phone::update() // battery > 10 && battery >= 10 ???
{
	if (batteryLevel < 10)
	{
		return;
	}
	batteryLevel -= 10;
	OSversion++;
}

void Phone::charge(int min)
{
	if (min <= 0) return;

	if (batteryLevel + min >= 100) batteryLevel = 100;
	else batteryLevel += min;
}

const char* Phone::getModel() const
{
	return model;
}

unsigned Phone::getBatteryLevel() const
{
	return batteryLevel;
}

unsigned Phone::getOSversion() const
{
	return OSversion;
}

unsigned Phone::getSoundLevel() const
{
	return soundLevel;
}

void Phone::setSoundLevel(unsigned level)
{
	if (level <= 10)
		soundLevel = level;
	else
		std::cout << "Invalid level\n";
}

void Phone::setModel(const char* model)
{
	delete[] this->model;
	if (!model)
	{
		this->model = new char[8];
		strcpy(this->model, "Unknown");
		return;
	}

	int len = strlen(model);
	this->model = new char[len + 1];
	strcpy(this->model, model);
}