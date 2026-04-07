#include <iostream>
#include "Product.h"

int main()
{
	Product p1 = { "bio milk", "100% bokluk", 1.50, true };
	Product p2 = { "bio chocolate", "10000% bokluk", 10.80, true };
	Product p3 = p1;

	p1.printProduct();
	p3.printProduct();

	p1.setName("Milk");
	p1.setDescription("Nai dobroto mleko na pazara!!!");
	p1.printProduct();

	p2.canBuy(2);
	p2.printProduct();

}