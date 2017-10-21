/*
 * product.c
 *
 *  Created on: Apr 22, 2016
 *      Author: Leonardo Perrone, f285y428
 *      Assignment: 4
 */

/*
 Description: This cpp file implements the Product class with its accessors, mutators and methods.

 */
#include <iostream> //including libraries
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include "product.h"
#include "productBatch.h"



//constructor
Product::Product(int product_id, std::string product_name, Category category, unsigned int storage_life) : m_product_id(product_id), m_product_name(product_name), m_category(category)
{

    if (category == PERISHABLE)
    {
        m_storage_life = storage_life;
    }
    else
    {
        m_storage_life = 0;
    }
}

Product::~Product() //destructor
{

    //delete [] m_batches;

}

int Product::product_id(void) const//accessor
{
    return m_product_id;
}

std::string Product::product_name(void) const //accessor
{
    return m_product_name;
}


unsigned int Product::get_storage_life(void) const //accessor
{
    return m_storage_life;
}

Category Product::category() const//accessor
{
    return m_category;
}

unsigned int Product::num_batches(void) const //accessor
{
    return m_batches.size();
}

ProductBatch* Product::batch(unsigned int i) const //pointer to batch function
{
    if (m_batches.at(i) != NULL) //if batch is valid returns batch
    {
        return m_batches.at(i);
    }
    else
    {
       return NULL;
    }
}

bool Product::set_category_and_storage(Category category, unsigned int days) //mutator to set both caregory and storage file
{

    bool done = false;


    if ((category == NONPERISHABLE && days == 0) || (category == PERISHABLE && days > 0))
    {

        m_category = category;
        m_storage_life = days;
        done= true;
        return done;

    }
    else
    {
        return done;
    }

}

bool Product::set_product_name(std::string product_name) //mutator that returns true if name is correct
{
    bool done = false;
    m_product_name = product_name;

    if (m_product_name == product_name)
    {
        done = true;
    }

    return done;

}


bool Product::receive(unsigned long amount, int receipt) //receive functions that lets the user add a number of a certain product to a batch
{
    bool done = false;

    ProductBatch *prod;

    prod = new ProductBatch(amount, receipt, *this, m_storage_life);

    m_batches.push_back(prod);



    return done;
}

bool Product::ship_from_batch(unsigned long amount, unsigned int b)//ships a certain amount of items from a batch subtracting it from the num_in_stock
{
    bool done = false;

    if (m_batches.at(b) != NULL)
        {
          m_batches.at(b)->ProductBatch::ship(amount);
            if (m_batches.at(b)->get_num_in_stock() == 0)
            {
                m_batches.erase(m_batches.begin()+b);
            }
            done =true;
            return done;
        }
    else
        {
            return done;
        }
    return done;
}

void Product::display_product(const Product *p) //displays product list and batches for each products
{

    std::cout << "Product ID: "<< p->product_id() << ", Name: " << p->product_name() << ", Category: ";

    if(category() == 0) std::cout << "PERISHABLE";
    else std::cout << "NONPERISHABLE";

   std::cout << ", Storage Life: "<< p->get_storage_life() << std::endl;

    std::cout  << p->num_batches() << " batches: " << std::endl;

    for (unsigned int i =0; i < p->num_batches(); i++)
    {
        std::cout << "   Number in stock: " << p->batch(i)->get_num_in_stock() << ", Received on: " << p->batch(i)->get_received_on() << ", Expires on: " << p->batch(i)->get_expires_on() << std::endl;
    }


}




