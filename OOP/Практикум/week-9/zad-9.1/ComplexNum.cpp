#include "ComplexNum.h"

ComplexNum::ComplexNum(int i, int r)
	:i(i), r(r)
{
}

ComplexNum ComplexNum::operator+(const ComplexNum& t)
{
	return ComplexNum(i + t.i, r + t.r);
}

ComplexNum& ComplexNum::operator+=(const ComplexNum& t)
{
	*this = *this + t;
	return *this;
}

ComplexNum ComplexNum::operator-(const ComplexNum& t)
{
	return ComplexNum(i - t.i, r - t.r);
}

ComplexNum& ComplexNum::operator-=(const ComplexNum& t)
{
	*this = *this - t;
	return *this;
}

ComplexNum ComplexNum::operator*(const ComplexNum& t)
{
	int real = r * t.r - i * t.i;
	int imag = r * t.i + i * t.r;

	return ComplexNum(real, imag);
}

ComplexNum& ComplexNum::operator*=(const ComplexNum& t)
{
	*this = *this * t;
	return *this;
}

ComplexNum ComplexNum::operator/(const ComplexNum& t)
{
	int denominator = t.r * t.r + t.i * t.i;

	if (denominator == 0)
	{
		throw std::runtime_error("Division by zero complex number");
	}

	int real = (r * t.r + i * t.i) / denominator;
	int imag = (i * t.r - r * t.i) / denominator;

	return ComplexNum(imag, real);
}

ComplexNum& ComplexNum::operator/=(const ComplexNum& t)
{
	*this = *this / t;
	return *this;
}

bool ComplexNum::operator==(const ComplexNum& t)
{
	return i == t.i && r == t.r;
}

bool ComplexNum::operator!=(const ComplexNum& t)
{
	return !(*this == t);
}

std::ostream& operator<<(std::ostream& t, const ComplexNum& c)
{
	t << c.r;

	if (c.i >= 0)
		t << " + " << c.i << "i";
	else
		t << " - " << -c.i << "i";

	return t;
}

std::istream& operator>>(std::istream& in, ComplexNum& c)
{
	in >> c.r >> c.i;
	return in;
}

float ComplexNum::operator()()
{
	return std::sqrt(r * r + i * i);
}