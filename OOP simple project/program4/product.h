/*
 * product.h
 *
 *  Created on: Apr 22, 2016
 *      Author: Leonardo Perrone, f285y428
 *      Assignment: 4
 */

/*
 Description: this is the header file for the class Product
 */
#ifndef PRODUCT_HPP_
#define PRODUCT_HPP_

#include <stdio.h> //including libriaries
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>

class ProductBatch; //forward declaration

enum Category { PERISHABLE, NONPERISHABLE };

class Product
{
public:
    // constructor and destructor
    Product(int product_id, std::string product_name, Category category, unsigned int storage_life);
    ~Product();

    // transfer of products
    bool receive(unsigned long amount, int receipt);

    // accessors
    int product_id(void) const;
    std::string product_name(void) const;
    Category category(void) const;
    void print_out();
    unsigned int get_storage_life(void) const;
    unsigned int num_batches(void) const; //returns the size of m_batches
    ProductBatch* batch(unsigned int i) const; //returns m_batches[i] if i valid, else NULL

    void display_product(const Product *p);


    bool ship_from_batch(unsigned long amount, unsigned int b);
    // mutators
    bool set_category_and_storage(Category category, unsigned int days);
    bool set_product_name(std::string product_name);

private:
    // data members

    int m_product_id;
    std::string m_product_name;
    Category m_category;
    unsigned int m_storage_life;
    std::vector<ProductBatch*> m_batches;
};


#endif /* PROGRAM1_HPP_ */
