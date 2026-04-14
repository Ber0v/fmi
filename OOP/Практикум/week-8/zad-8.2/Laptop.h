#pragma once
#include "CPU.h"
#include "Display.h"
class Laptop
{
public:
	Laptop();
	Laptop(const CPU& cpu, const Display& display, const char* brand);
	Laptop(const Laptop& other);
	Laptop& operator=(const Laptop& other);
	~Laptop();

	void serializeText(std::ofstream& ofs) const;
	void deserializeText(std::ifstream& ifs);

	void serializeBinary(std::ofstream& ofs) const;
	void deserializeBinary(std::ifstream& ifs);

	//getter
	const CPU& getcpu() const;
	const Display& getDisplay() const;
	const char* getbrand() const;

	//setter
	void setcpu(const CPU& cpu);
	void setDisplay(const Display& display);

private:
	void free();
	void setbrand(const char* brand);

private:
	CPU cpu;
	Display display;
	char* brand;
};