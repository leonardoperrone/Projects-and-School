/*
 * productBatch.cpp
 *
 *  Created on: Apr 22, 2016
 *      Author: Leonardo Perrone, f285y428
 *      Assignment: 4
 */


/*
 Description: This cpp file implements the ProductBatch class with its accessors, mutators and methods.

 */


#include <iostream> //including libraries
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include "productBatch.h"



class Product;

//constructor
ProductBatch::ProductBatch(unsigned long num_in_stock, int received_on, Product &product, int num_storage_days): m_num_in_stock(num_in_stock), m_received_on(received_on), m_product(product), m_num_storage_days(num_storage_days)
{

    if (product.category() == PERISHABLE)
    {
        m_expires_on = m_num_storage_days + m_received_on;
    }

    else if (product.category() == NONPERISHABLE)

    {
        m_expires_on = 0;
    }

}


//destructor
ProductBatch::~ProductBatch()
{


}

unsigned long ProductBatch::get_num_in_stock(void) const //accessor
{
    return m_num_in_stock;
}

int ProductBatch::get_expires_on(void) const //accessor
{
    return m_expires_on;
}

int ProductBatch::get_received_on(void) const //accessor
{
    return m_received_on;

}

int ProductBatch::get_num_storage_days(void) const //accessor
{
    return m_num_storage_days;
}

bool ProductBatch::ship(unsigned long amount) //ship functions that lets subtract a number of products to the stock only if there are enough of that product
{
    bool done = false;

    if (get_num_in_stock() >= amount)
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


bool ProductBatch::expire_process(void) //return true if number in stock is positive
{
    bool done = true;

    if (get_num_in_stock() > 0)
    {
        ship(get_num_in_stock());
        done = true;
        return done;

    }
    else
    {
        return done;
    }

}


void ProductBatch::display_batch(const ProductBatch *b) //displays batches of a product
{

    std::cout << "Number in stock: "<< b->get_num_in_stock() << ", Received on " << b->get_received_on()  << ", Expires on " << b->get_expires_on()  << std::endl;
    std::cout << std::endl;



}








