#include "Laptop.h"

Laptop::Laptop()
	:brand(nullptr)
{
	setbrand("Unknown");
}

Laptop::Laptop(const CPU& cpu, const Display& display, const char* brand)
	:cpu(cpu), display(display), brand(nullptr)
{
	setbrand(brand);
}

Laptop::Laptop(const Laptop& other)
	:cpu(other.cpu), display(other.display), brand(nullptr)
{
	setbrand(other.brand);
}

Laptop& Laptop::operator=(const Laptop& other)
{
	if (&other == this) return *this;

	Laptop temp(other);
	std::swap(cpu, temp.cpu);
	std::swap(display, temp.display);
	std::swap(brand, temp.brand);

	return *this;
}

Laptop::~Laptop()
{
	free();
}

void Laptop::serializeText(std::ofstream& ofs) const
{
	if (!ofs.is_open()) return;

	cpu.serializeText(ofs);
	display.serializeText(ofs);
	ofs << brand << '\n';
}

void Laptop::deserializeText(std::ifstream& ifs)
{
	if (!ifs.is_open()) return;

	cpu.deserializeText(ifs);
	display.deserializeText(ifs);

	char buffer[1024];
	if (!ifs.getline(buffer, 1024)) return;

	setbrand(buffer);
}

void Laptop::serializeBinary(std::ofstream& ofs) const
{
	if (!ofs.is_open()) return;

	cpu.serializeBinary(ofs);
	display.serializeBinary(ofs);

	size_t len = strlen(brand);
	ofs.write((const char*)&len, sizeof(len));
	if (!ofs.good()) return;

	ofs.write(brand, len);
	if (!ofs.good()) return;
}

void Laptop::deserializeBinary(std::ifstream& ifs)
{
	if (!ifs.is_open()) return;

	cpu.deserializeBinary(ifs);
	display.deserializeBinary(ifs);

	size_t len = 0;
	ifs.read((char*)&len, sizeof(len));
	if (!ifs.good()) return;

	char* buffer = new char[len + 1];

	ifs.read(buffer, len);
	if (!ifs.good())
	{
		delete[] buffer;
		return;
	}

	buffer[len] = '\0';

	setbrand(buffer);
	delete[] buffer;
}

const CPU& Laptop::getcpu() const
{
	return cpu;
}

const Display& Laptop::getDisplay() const
{
	return display;
}

const char* Laptop::getbrand() const
{
	return brand;
}

void Laptop::setcpu(const CPU& cpu)
{
	this->cpu = cpu;
}

void Laptop::setDisplay(const Display& display)
{
	this->display = display;
}

void Laptop::free()
{
	delete[] brand;
	brand = nullptr;
}

void Laptop::setbrand(const char* brand)
{
	int len = strlen(brand);
	char* temp = new char[len + 1];
	strcpy(temp, brand);

	free();
	this->brand = temp;
}