/*
 * manage.c
 *
 *  Created on: Apr 22, 2016
 *      Author: Leonardo Perrone, f285y428
 *      Assignment: 4

 Description : This program lets the user create a product with an ID, a name and a category of perishable or nonperishable and a life of storage.
 It lets the user create batches for a specific product and ship items from those batches of those specific products. It also will let the user see all the existing products and batches.

 */


#include <stdio.h> //including libriaries
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "product.h"
#include "productBatch.h"


Product *add_product(void) //add a product fucntion, return the new product
{
    int prod_id;
    std::string prod_name;
    int choice;
    Category prod_cat = PERISHABLE;
    unsigned int prod_life;
    int p = 4;
    Product *prod1;

    //getting parameters
    std::cout << "Enter product ID: ";
    std::cin >> prod_id;
    std::cout << "Enter product name: ";
    std::cin.get();
    std::getline(std::cin, prod_name);
    std::cout << "Enter category (1=Perishable, 2=Nonperishable): ";
    std::cin >> choice;

    while (p > 3)
    {
    switch (choice) //switch statement to see if product is perishable or not, and return the product accrdingly
        {
        case 1:
                prod_cat = PERISHABLE;
                p = 1;
                std::cout << "Enter the storage life in days: ";
                std::cin >> prod_life;

                prod1 = new Product(prod_id, prod_name, prod_cat, prod_life);
                std::cout << "Product Added" << std::endl;
                std::cout << std::endl;
                return prod1;
                break;

            case 2:
                prod_cat = NONPERISHABLE;
                p = 2;

                prod1 = new Product(prod_id, prod_name, prod_cat, 0);
                std::cout << "Product Added" << std::endl;
                std::cout << std::endl;
                return prod1;
                break;

        default:
                p = 4;
                break;
        }
    }

    return prod1;


}

bool receive_batch(std::vector<Product*> &prod_list) //function to receive a new batch of a product
{
    int i, received;
    unsigned long num;
    bool done = false;

    std::cout << "A batch can only be added for a product that exists. If the product is not yet in the product list, return to the main menu, add the product, then return to add the batch.";
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "List of current products:" << std::endl;




    for (unsigned i = 0; i < prod_list.size(); i++) //displays current products names
    {

        std::cout << "  " << i+1 << ". " << prod_list.at(i)->product_name() << std::endl;

    }

    std::cout << "Enter the number of the product from the list above (or any other number to return to the main menu): ";
    std::cin >> i;

    if (prod_list.at(i-1) != NULL) //calls for the receive function that creates the new batch with the user input parameters
    {
    std::cout << std::endl;
    std::cout << "Enter number of items received: ";
    std::cin >> num;
    std::cout << "Enter day received: ";
    std::cin >> received;

    prod_list.at(i-1)->receive(num, received);

    std::cout << "Batch added" << std::endl;
    std::cout << std::endl;
        done = true;
     return done;
    }
    else
    {
        return done;
    }
}

bool ship_from_batch(std::vector<Product*> &prod_list) //function to ship items from a bacth of some product
{
    int i;
    unsigned long num;
    unsigned int batch;
    bool done = false;
    std::cout << "It is only possible to ship from an existing batch of an existing product. Selecting a product or batch that doesn’t exist will return to the main menu." << std::endl;

    std::cout << "List of products:" << std::endl;

    for (unsigned i = 0; i < prod_list.size(); i++) //shows list of products' names
    {

        std::cout << "  " << i+1 << ". " << prod_list.at(i)->product_name() << std::endl;

    }

    std::cout << std::endl;
    std::cout << "Enter the number of the product from the list above (or any other number to return to the main menu): ";
    std::cin >> i;
    if (prod_list.at(i-1) != NULL) //if the product exists it will show the batches of that products
    {
    std::cout << std::endl;
    std::cout << "List of batches: " << std::endl;
        for (unsigned int q =0; q < prod_list.at(i-1)->num_batches(); q++) //displays all batches
        {
            std::cout << "  " << q+1 << ". ";
            prod_list.at(i-1)->batch(i-1)->display_batch(prod_list.at(i-1)->batch(i-1));
        }


    std::cout << "Enter the number of the batch from the list above (or any other number to return to the main menu): ";
    std::cin >> batch;
    std::cout << std::endl;
    std::cout << "Enter number of items to ship: ";
    std::cin >> num ;

    prod_list.at(i-1)->ship_from_batch(num, batch-1); //calls for product function to ship items

    std::cout << "Items shipped" << std::endl;
    std::cout << std::endl;
        done = true;
        return done;
    }
    else
    {
        return done;
    }

}









int main() //main function with 5 options menu for the user to select
{
   std::vector<Product*> products; //declares a vector of type Product

    //declaring functions
    Product *add_product(void);
    bool receive_batch(const std::vector<Product*> &prod_list);
    bool ship_from_batch(const std::vector<Product*> &prod_list);
    void display_product(const Product *p);
    void display_batch(const ProductBatch *b);
    int q =0;
    int menu_choice;


    while (q < 5 ) //loop for menu to quit if 5 is entered
    {
        //menu options
    std::cout << "Available options:" << std::endl;
    std::cout << "  1. Add new product" << std::endl;
    std::cout << "  2. Receive batch of some product" << std::endl;
    std::cout << "  3. Ship from batch of some product" << std::endl;
    std::cout << "  4. Show all products" << std::endl;
    std::cout << "  5. Quit" << std::endl;
    std::cout << "Enter the number of your choice: " ;

    std::cin >> menu_choice;
        std::cout << std::endl;

      //switch with 5 options
            switch (menu_choice)
            {
                case 1:
                    products.push_back(add_product()); //calls for add product and adds new product in vector or products
                    break;
                case 2:
                    receive_batch(products); //calls for receive function with products as parameter
                    break;
                case 3:
                    ship_from_batch(products); //calls for ship_from_batch function
                    break;

                case 4:
                    for (unsigned int i = 0; i < products.size(); i++) //loops that shows products and batches
                    {

                        products.at(i)->display_product(products.at(i));

                    }

                    break;


            default:
                    q= 6; //quits the program
                break;
            }
    }
}








