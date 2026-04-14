#pragma once
#include <fstream>
class CPU
{
public:
	CPU();
	CPU(const char* model, int clockSpeed);
	CPU(const CPU& other);
	CPU& operator=(const CPU& other);
	~CPU();

	void serializeText(std::ofstream& ofs) const;
	void deserializeText(std::ifstream& ifs);

	void serializeBinary(std::ofstream& ofs) const;
	void deserializeBinary(std::ifstream& ifs);

	//getter
	const char* getModel() const;
	int getClockSpeed() const;

private:
	void free();
	void setModel(const char* model);
	void setClockSpeed(int clockSpeed);
private:
	char* model;
	int clockSpeed;
};