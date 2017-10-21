/*
 * manage.c
 *
 *  Created on: Feb 1, 2016
 *      Author: Leonardo Perrone, f285y428
 *      Assignment: 1
 
 Description : This program lets the user create a product with an ID, a name and a category of perishable or nonperishable. It lets the user add and subtract to the stock a certain number of the product in question with a starting number of 0 as default.
 
 */


#include <stdio.h> //including libriaries
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "product.hpp"

int main() //main function testing objects of the class
{
	Product product_1 = Product(23, "Chair", PERISHABLE); //automatically allocated product
	product_1.print_out();

	Product *product_2; //pointer to new product

	product_2 = new Product(2, "Arm Chair", PERISHABLE); //dinamically allocated product

	product_2-> print_out(); // testing outcome
	product_2-> set_category(NONPERISHABLE);
    product_2-> set_product_name("Recline Chair");
	product_2-> receive(200);

	product_2-> print_out();

	product_2 -> set_category(PERISHABLE);
	product_2 -> ship(100);
	product_2 -> ship(25);
	product_2 -> print_out(); 
}
