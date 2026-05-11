#include "Nvector.h"

Nvector& Nvector::operator+=(const Nvector& vr)
{
	x = x + vr.x;
	y = y + vr.y;
	z = z + vr.z;

	return *this;
}

Nvector Nvector::operator+(const Nvector& vr)
{
	return Nvector(x += vr.x, y += vr.y, z += vr.z);
}

Nvector& Nvector::operator-=(const Nvector& vr)
{
	// TODO: insert return statement here
}

Nvector Nvector::operator-(const Nvector& vr)
{
	return Nvector();
}

Nvector& Nvector::operator*=(const int sk)
{
	// TODO: insert return statement here
}

Nvector Nvector::operator*(const int sk)
{
	return Nvector();
}

Nvector& Nvector::operator*=(const Nvector vr)
{
	// TODO: insert return statement here
}

Nvector Nvector::operator*(const Nvector vr)
{
	return Nvector();
}

double Nvector::operator()(const Nvector& vr)
{
	return 0.0;
}

int Nvector::operator[](const Nvector& vr)
{
	return 0;
}

std::ostream& operator<<(std::ostream& out, const Nvector& vr)
{
	// TODO: insert return statement here
}

std::istream& operator>>(std::istream& in, const Nvector& vr)
{
	// TODO: insert return statement here
}
