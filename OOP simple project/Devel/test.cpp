#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "raw_material.hpp"
#include "product.hpp"
#include "order.hpp"
#include "refine.hpp"

using namespace std;

int main(void)
{

	RawMaterial* raw_material = new RawMaterial("Iron Ore", 5, 1, -1,
                                                         -1, 10, 0, 0, 0, 0);

	Product* product = new Product("Copper Wire", 100, 5, 8, -1, 2,
                                            4, 0, 1);

	raw_material->print_all();
	product->print_all();

	return 0;
}
