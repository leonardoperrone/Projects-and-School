/*
 * product.c
 *
 *  Created on: Feb 1, 2016
 *      Author: Leonardo Perrone, f285y428
 *      Assignment: 1
 */

#include <iostream> //including libraries
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "product.hpp"


Product::Product(int product_id, std::string product_name, Category category) //constructor
{
m_product_id = product_id;
m_product_name = product_name;
m_category = category;
m_num_in_stock = 0;

}

int Product::product_id(void) //accessor 
{
	return m_product_id;
}

std::string Product::product_name(void) //accessor
{
	return m_product_name;
}

unsigned long Product::num_in_stock() //accessor
{
	return m_num_in_stock;
}

Category Product::category() //accessor
{
	return m_category;
}

bool Product::set_category(Category category) //mutator that returns true unless user enters wrong category
{
	bool done = false;
	m_category = category;

	if (m_category == category)
	{
		done = true;
	}
    else
    {
        std::cout << "ERROR: Could not change category" << std::endl;
    }
    
	return done;
}

bool Product::set_product_name(std::string product_name) //mutator that returns true
{
	bool done = false;
	m_product_name = product_name;

	if (m_product_name == product_name)
	{
		done = true;
	}

	return done;

}


bool Product::receive(unsigned long amount) //receive functions that lets add a positive number of products to the stock
{
	bool done = false;

	if (amount > 0)
	{
		m_num_in_stock = m_num_in_stock + amount;
		done = true;
	}
	else
	{
		std::cout << "ERROR: Product not received" << std::endl;

	}

	return done;
}

bool Product::ship(unsigned long amount) //ship functions that lets subtract a number of products to the stock only if there are enough of that product
{
	bool done = false;

	if (m_num_in_stock > amount)
	{
		m_num_in_stock = m_num_in_stock - amount;
		done = true;
	}
	else
	{
		std::cout << "ERROR: Invalid shipment complete" << std::endl;

	}

	return done;
}

void Product::print_out() //print out fucntion to check the outcome
{
	std::cout << "Product ID: " << product_id() << ", Name: "
			<< product_name() << ", Category: " ;

	if(category() == 0) std::cout << "PERISHABLE" << std::endl;
	else std::cout << "NONPERISHABLE" << std::endl;

	std::cout << "Number in Stock: " << num_in_stock() << std::endl;
}








