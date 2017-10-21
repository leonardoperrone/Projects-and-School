/*
 * product.h
 *
 *  Created on: Feb 1, 2016
 *      Author: Leonardo Perrone, f285y428
 *      Assignment: 1
 */

#ifndef PRODUCT_HPP_
#define PRODUCT_HPP_

#include <stdio.h> //including libriaries
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>

enum Category { PERISHABLE, NONPERISHABLE };

class Product
{
public:
// constructor and destructor
	Product(int product_id, std::string product_name, Category category);

// transfer of products
bool receive(unsigned long amount);
bool ship(unsigned long amount);

// accessors
int product_id(void);
std::string product_name(void);
Category category(void);
unsigned long num_in_stock(void);
void print_out();

// mutators
bool set_category(Category category);
bool set_product_name(std::string product_name);

private:
// data members

int m_product_id;
std::string m_product_name;
Category m_category;
unsigned long m_num_in_stock;
};


#endif /* PROGRAM1_HPP_ */
