#include "CPU.h"

CPU::CPU()
	:model(nullptr), clockSpeed(0)
{
	setModel("NoModel");
}

CPU::CPU(const char* model, int clockSpeed)
	:model(nullptr)
{
	setModel(model);
	setClockSpeed(clockSpeed);
}

CPU::CPU(const CPU& other)
	:model(nullptr), clockSpeed(other.clockSpeed)
{
	setModel(other.model);
}

CPU& CPU::operator=(const CPU& other)
{
	if (&other == this) return *this;

	CPU temp(other);
	std::swap(model, temp.model);
	std::swap(clockSpeed, temp.clockSpeed);

	return *this;
}

CPU::~CPU()
{
	free();
}

void CPU::serializeText(std::ofstream& ofs) const
{
	if (!ofs.is_open()) return;

	ofs << model << '\n';
	ofs << clockSpeed << '\n';
}

void CPU::deserializeText(std::ifstream& ifs)
{
	if (!ifs.is_open()) return;

	char buffer[1024];

	if (!ifs.getline(buffer, 1024)) return;
	setModel(buffer);

	if (!(ifs >> clockSpeed)) return;

	ifs.ignore();
}

void CPU::serializeBinary(std::ofstream& ofs) const
{
	if (!ofs.is_open()) return;

	size_t len = strlen(model);

	ofs.write((const char*)&len, sizeof(len));
	if (!ofs.good()) return;

	ofs.write(model, len);
	if (!ofs.good()) return;

	ofs.write((const char*)&clockSpeed, sizeof(clockSpeed));
}

void CPU::deserializeBinary(std::ifstream& ifs)
{
	if (!ifs.is_open()) return;

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

	setModel(buffer);
	delete[] buffer;

	ifs.read((char*)&clockSpeed, sizeof(clockSpeed));
}

const char* CPU::getModel() const
{
	return model;
}

int CPU::getClockSpeed() const
{
	return clockSpeed;
}

void CPU::free()
{
	delete[] model;
	model = nullptr;
}

void CPU::setModel(const char* model)
{
	int len = strlen(model);
	char* temp = new char[len + 1];
	strcpy(temp, model);

	free();
	this->model = temp;
}

void CPU::setClockSpeed(int clockSpeed)
{
	if (clockSpeed < 0)
	{
		this->clockSpeed = 0;
		return;
	}
	this->clockSpeed = clockSpeed;
}
