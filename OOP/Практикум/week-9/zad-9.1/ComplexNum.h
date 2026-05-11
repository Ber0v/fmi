#pragma once
#include <fstream>
class ComplexNum
{
public:
	ComplexNum(int i, int r);

	ComplexNum operator+(const ComplexNum& t);
	ComplexNum& operator+=(const ComplexNum& t);

	ComplexNum operator-(const ComplexNum& t);
	ComplexNum& operator-=(const ComplexNum& t);

	ComplexNum operator*(const ComplexNum& t);
	ComplexNum& operator*=(const ComplexNum& t);

	ComplexNum operator/(const ComplexNum& t);
	ComplexNum& operator/=(const ComplexNum& t);

	friend std::ostream& operator<<(std::ostream& t, const ComplexNum& c);
	friend std::istream& operator>>(std::istream& t, ComplexNum& c);

	bool operator==(const ComplexNum& t);
	bool operator!=(const ComplexNum& t);

	float operator()();

private:
	int i;
	int r;
};