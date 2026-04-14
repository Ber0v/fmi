#include <iostream>
#include "Student.h"

int main()
{
	Student one("Gosho", 2002, 4);
	Student two = one;
	two.printStudent();
}