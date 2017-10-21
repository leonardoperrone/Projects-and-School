/*
 * productBatch.hpp
 *
 *  Created on: Apr 22, 2016
 *  Author: Leonardo Perrone, f285y428
 *  Assignment: 4
 */

/*
 Description: this is the header file for the class ProductBatch


 */
#ifndef __program4xcode__productBatch__
#define __program4xcode__productBatch__

#include <stdio.h> //including libriaries
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include "product.h"

class ProductBatch
{
public:
    //constructor
    ProductBatch(unsigned long num_in_stock, int received_on, Product &product, int num_storage_days);
    ~ProductBatch();

    // transfer of products
    bool ship(unsigned long amount);
    bool expire_process(void);

    //accessors
    unsigned long get_num_in_stock(void) const;
    int get_received_on(void) const;
    int get_expires_on(void) const;
    int get_num_storage_days(void) const;
    Product get_product(void);

    void display_batch(const ProductBatch *b);



private:
    unsigned long m_num_in_stock;
    int m_received_on;
    int m_expires_on;
    int m_num_storage_days;
    Product& m_product; //reference


};

#endif /* defined(__program4xcode__productBatch__) */
