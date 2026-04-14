#include "Display.h"

Display::Display()
	:Display(0, 0, 0)
{
}

Display::Display(int refreshRate, int width, int heigth)
{
	setRefreshRate(refreshRate);
	setWidth(width);
	setHeight(heigth);
}

void Display::serializeText(std::ofstream& ofs) const
{
	if (!ofs.is_open()) return;

	ofs << refreshRate << '\n';
	ofs << width << '\n';
	ofs << height << '\n';
}

void Display::deserializeText(std::ifstream& ifs)
{
	if (!ifs.is_open()) return;

	if (!(ifs >> refreshRate)) return;
	if (!(ifs >> width)) return;
	if (!(ifs >> height)) return;

	ifs.ignore();
}

void Display::serializeBinary(std::ofstream& ofs) const
{
	if (!ofs.is_open()) return;

	ofs.write((const char*)&refreshRate, sizeof(refreshRate));
	ofs.write((const char*)&width, sizeof(width));
	ofs.write((const char*)&height, sizeof(height));
}

void Display::deserializeBinary(std::ifstream& ifs)
{
	if (!ifs.is_open()) return;

	ifs.read((char*)&refreshRate, sizeof(refreshRate));
	if (!ifs.good()) return;

	ifs.read((char*)&width, sizeof(width));
	if (!ifs.good()) return;

	ifs.read((char*)&height, sizeof(height));
	if (!ifs.good()) return;
}

int Display::getRefreshRate() const
{
	return refreshRate;
}

int Display::getWidth() const
{
	return width;
}

int Display::getHeight() const
{
	return height;
}

void Display::setRefreshRate(int refreshRate)
{
	if (refreshRate < 0)
	{
		this->refreshRate = 0;
		return;
	}
	this->refreshRate = refreshRate;
}

void Display::setWidth(int width)
{
	if (width < 0)
	{
		this->width = 0;
		return;
	}
	this->width = width;
}

void Display::setHeight(int height)
{
	if (height < 0)
	{
		this->height = 0;
		return;
	}
	this->height = height;
}
