#pragma once
#include <fstream>
class Display
{
public:
	Display();
	Display(int refreshRate, int width, int heigth);

	void serializeText(std::ofstream& ofs) const;
	void deserializeText(std::ifstream& ifs);

	void serializeBinary(std::ofstream& ofs) const;
	void deserializeBinary(std::ifstream& ifs);

	//getter
	int getRefreshRate() const;
	int getWidth() const;
	int getHeight() const;

	//setter
	void setRefreshRate(int refreshRate);
	void setWidth(int width);
	void setHeight(int height);

private:
	int refreshRate;
	int width;
	int height;
};