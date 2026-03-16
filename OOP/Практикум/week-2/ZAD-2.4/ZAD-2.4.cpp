#include <iostream>

struct ComplexNum
{
	double realNum;
	double imaginaryNum;
};

ComplexNum complexNum(double x, double y)
{
	ComplexNum num = { x, y };
	return num;
}

void printComplex(const ComplexNum n)
{
	std::cout << '(' << n.realNum << " + " << n.imaginaryNum << "i)" << '\n';
}

ComplexNum sumComplex(const ComplexNum a, const ComplexNum b)
{
	ComplexNum result;
	result.realNum = a.realNum + b.realNum;
	result.imaginaryNum = a.imaginaryNum + b.imaginaryNum;
	return result;
}

int main()
{
	ComplexNum p = complexNum(3, 5);
	ComplexNum c = complexNum(4, 3);
	printComplex(p);
	ComplexNum g = sumComplex(p, c);
	printComplex(g);
}