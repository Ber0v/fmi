#pragma once
#include <ostream>
class Nvector
{
public:
	Nvector& operator+=(const Nvector& vr);
	Nvector operator+(const Nvector& vr);

	Nvector& operator-=(const Nvector& vr);
	Nvector operator-(const Nvector& vr);

	Nvector& operator*=(const int sk);
	Nvector operator*(const int sk);

	Nvector& operator*=(const Nvector vr);
	Nvector operator*(const Nvector vr);

	double operator()(const Nvector& vr);

	int operator[](const Nvector& vr);

	friend
		std::ostream& operator<<(std::ostream& out, const Nvector& vr);
	friend
		std::istream& operator>>(std::istream& in, const Nvector& vr);
private:
	int x;
	int y;
	int z;
};